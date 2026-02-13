/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:30:06 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/13 15:22:28 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	random_direction()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec) % 4);
}

int	patrol_new_place(t_data *data, int y, int x)
{
	if (data->map->crd[y][x] == 'P')
		game_lose(data);
	if (data->map->crd[y][x] == '0')
	{
		data->map->crd[y][x] = 'S';
		return (1);
	}
	return (0);
}

void	where_go_patrol(t_data *data, int y, int x)
{
	int		random;
	char	status;

	status = 0;
	random = random_direction();
	if (random == 0)
		status |= patrol_new_place(data, y - 1, x);
	else if (random == 1)
		status |= patrol_new_place(data, y + 1, x);
	else if (random == 2)
		status |= patrol_new_place(data, y, x - 1);
	else if (random == 3)
		status |= patrol_new_place(data, y, x + 1);
	if (status)
		data->map->crd[y][x] = '0';
}

void	move_patrol(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (data->map->e > i)
	{
		x = data->map->patrol_x[i];
		y = data->map->patrol_y[i];
		where_go_patrol(data, y, x);
		i++;
	}
}
