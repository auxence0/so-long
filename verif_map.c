/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:15:09 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/04 11:26:01 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_wall_map(char **map)
{
	int	i;

	i = 0;
	ft_printf("Error : The map is not properly surrounded by walls.\n");
	free_tab(map);
	exit(1);
}

void	error_obj_map(t_map *map)
{
	int	i;

	if (map->e == 0)
		ft_printf("Error : The exit is missing\n");
	if (map->e > 1)
		ft_printf("Error : There is more than 1 exit\n");
	if (map->c == 0)
		ft_printf("Error : A collectible is missing\n");
	if (map->p == 0)
		ft_printf("Error : The player is missing\n");
	if (map->p > 1)
		ft_printf("Error : There is too many players\n");
	i = 0;
	free_tab(map->crd);
	exit(1);
}

void	verif_obj_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
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
	if (map->e != 1 || map->c < 1 || map->p != 1)
		error_obj_map(map);
}

void	verif_acces_collectible(t_map *map, int y, int x)
{
	flood_fill(map, y, x);
	if (map->c == map->verif_c && map->verif_e == 1)
		return ;
	else
	{
		if (map->verif_e < 1)
			ft_printf("Error : There is no exit accessible\n");
		if (map->c - map->verif_c == 1)
			ft_printf("Error : The collectible is not accessible\n");
		else if (map->c - map->verif_c != 0)
			ft_printf("Error : Collectibles are not accessible\n");
		free_tab(map->crd);
		free_tab(map->tmp_map);
		exit(1);
	}
}

void	verif_walls(t_map *map)
{
	char	status;
	int		y;
	int		x;

	status = 0;
	x = 0;
	y = 0;
	while (x < map->width)
	{
		status |= (map->crd[0][x] != '1');
		status |= (map->crd[map->height - 1][x++] != '1');
	}
	while (y < map->height)
	{
		status |= (map->crd[y][0] != '1');
		status |= (map->crd[y++][map->width - 1] != '1');
	}
	if (status)
		error_wall_map(map->crd);
}
