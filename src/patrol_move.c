/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:30:06 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/15 16:28:20 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	random_direction(void)
{
	struct timeval	time;
	static int		random;
	static int		init;

	if (!init)
	{
		gettimeofday(&time, NULL);
		random = time.tv_usec;
		init = 1;
	}
	random = (random * 1103515245 + 12345) & 2147483647;
	return ((random >> 16) % 4);
}

int	patrol_new_place(t_data *data, int y, int x, int i)
{
	if (data->map->crd[y][x] == 'P')
	{
		game_lose(data);
		return (2);
	}
	else if (data->map->crd[y][x] == '0')
	{
		data->map->patrol_x[i] = x;
		data->map->patrol_y[i] = y;
		data->map->crd[y][x] = 'S';
		return (1);
	}
	return (0);
}

int	where_go_patrol(t_data *data, int y, int x, int i)
{
	int		random;
	char	status;

	status = 0;
	while (!status)
	{
		random = random_direction();
		if (random == 0)
			status |= patrol_new_place(data, y - 1, x, i);
		else if (random == 1)
			status |= patrol_new_place(data, y + 1, x, i);
		else if (random == 2)
			status |= patrol_new_place(data, y, x - 1, i);
		else if (random == 3)
			status |= patrol_new_place(data, y, x + 1, i);
		if (status == 1)
			data->map->crd[y][x] = '0';
	}
	return (status);
}

int	check_movement(t_map *map, int y, int x)
{
	if (map->crd[y + 1][x] == '0' || map->crd[y + 1][x] == 'P')
		return (1);
	else if (map->crd[y - 1][x] == '0' || map->crd[y + 1][x] == 'P')
		return (1);
	else if (map->crd[y][x + 1] == '0' || map->crd[y + 1][x] == 'P')
		return (1);
	else if (map->crd[y][x - 1] == '0' || map->crd[y + 1][x] == 'P')
		return (1);
	return (0);
}

int	move_patrol(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (data->map->s > i)
	{
		x = data->map->patrol_x[i];
		y = data->map->patrol_y[i];
		if (check_movement(data->map, y, x))
		{
			if (where_go_patrol(data, y, x, i) == 2)
				return (0);
		}
		i++;
	}
	return (1);
}
