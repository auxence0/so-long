/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:15:09 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/26 13:22:51 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_wall_map(char **map)
{
	int	i;

	i = 0;
	ft_putstr_fd("The map is not properly surrounded by walls.\n", 2);
	if (!map)
		exit(1);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(1);
}

void	error_obj_map(t_map *map)
{
	int	i;

	if (map->e == 0)
		ft_putstr_fd("The exit is missing\n", 2);
	if (map->c == 0)
		ft_putstr_fd("A collectible is missing\n", 2);
	if (map->p == 0)
		ft_putstr_fd("The player is missing\n", 2);
	if (map->p > 1)
		ft_putstr_fd("There is too many players\n", 2);
	i = 0;
	while (map->crd && map->crd[i])
	{
		free(map->crd[i]);
		i++;
	}
	if (map->crd)
		free(map->crd);
	exit(1);
}

void	verif_obj_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->s = 0;
	while (map->crd[y])
	{
		x = 0;
		while (map->crd[y][x])
		{
			add_obj(map->crd[y][x], map);
			x++;
		}
		y++;
	}
	if (map->e < 1 || map->c < 1 || map->p != 1)
		error_obj_map(map);
}

void	verif_acces_collectible(t_map *map, int y, int x)
{
	int	count_collectible;

	count_collectible = flood_fill(map, y, x);
	if (map->c == count_collectible)
		return ;
	else
	{
		if (map->c == 1)
			ft_putstr_fd("The collectible is not accessible\n", 2);
		else
			ft_putstr_fd("Collectible are not accessible\n", 2);
		exit(1);
	}
}

void	verif_walls(t_map *map, int x, int y)
{
	x = 0;
	while (map->crd[0] && map->crd[0][x])
	{
		if (map->crd[0][x++] != '1')
			error_wall_map(map->crd);
	}
	y = 0;
	while (map->crd[y] && map->crd[y][0])
	{
		if (map->crd[y++][0] != '1')
			error_wall_map(map->crd);
	}
	y = 0;
	while (map->crd[y] && map->crd[y][map->width - 1])
	{
		if (map->crd[y++][map->width - 1] != '1')
			error_wall_map(map->crd);
	}
	x = 0;
	while (map->crd[map->height - 1] && map->crd[map->height - 1][x])
	{
		if (map->crd[map->height - 1][x++] != '1')
			error_wall_map(map->crd);
	}
}
