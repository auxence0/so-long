/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:30:06 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/11 17:05:02 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	random_direction()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec) % 4);
}

int	patrol_new_place(t_data *data, int y, int x, char **map)
{
	if (data->map->crd[y][x] == 'P')
	{
		free_tab(map);
		game_lose(data);
	}
	if (data->map->crd[y][x] == '0')
	{
		data->map->crd[y][x] = 'S';
		return (1);
	}
	return (0);
}

void	where_go_patrol(t_data *data, int y, int x, char **map)
{
	int		random;
	char	status;

	status = 0;
	random = random_direction();
	if (random == 0)
		status |= patrol_new_place(data, y - 1, x, map);
	else if (random == 1)
		status |= patrol_new_place(data, y + 1, x, map);
	else if (random == 2)
		status |= patrol_new_place(data, y, x - 1, map);
	else if (random == 3)
		status |= patrol_new_place(data, y, x + 1, map);
	if (status)
		data->map->crd[y][x] = '0';
}

void	move_patrol(t_data *data)
{
	int		x;
	int		y;
	char	**tmp_map;

	tmp_map = ft_strstrdup(data->map->crd, data->map);
	y = 0;
	while (tmp_map[y])
	{
		x = 0;
		while (tmp_map[y][x])
		{
			if (tmp_map[y][x] == 'S')
				where_go_patrol(data, y, x, tmp_map);
			x++;
		}
		y++;
	}
	free_tab(tmp_map);
}
