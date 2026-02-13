/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_patrols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:10:32 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/13 15:18:48 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_patrold(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map->crd[y])
	{
		x = 0;
		while (map->crd[y][x])
		{
			if (map->crd[y][x] == 'S')
			{
				map->patrol_x[i] = x;
				map->patrol_y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	start_patrols(t_map *map)
{
	map->patrol_x = malloc(sizeof(int) * map->e);
	if (!map->patrol_x)
	{
		free_tab(map->crd);
		exit (1);
	}
	map->patrol_y = malloc(sizeof(int) * map->e);
	if (!map->patrol_y)
	{
		free_tab(map->crd);
		exit (1);
	}
}
