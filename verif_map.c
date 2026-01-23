/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:15:09 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/23 18:47:37 by asauvage         ###   ########.fr       */
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

void	error_obj_map(t_map *map, t_element elt)
{
	int	i;

	if (elt.e == 0)
		ft_putstr_fd("The exit is missing\n", 2);
	if (elt.c == 0)
		ft_putstr_fd("A colllectible is missing\n", 2);
	if (elt.p == 0)
		ft_putstr_fd("The player is missing\n", 2);
	i = 0;
	while (map->crd && map->crd[i])
	{
		free(map->crd[i]);
		i++;
	}
	if (map->crd)
		free(map->crd);
	exit (1);
}

void	verif_obj_map(t_map *map)
{
	t_element	elt;
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_memset(&elt, 0, sizeof(t_element));
	while (map->crd[i][j])
	{
		j = 0;
		while (map->crd[i][j])
		{
			if (map->crd[i][j] == 'E')
				elt.e += 1;
			if (map->crd[i][j] == 'C')
				elt.c += 1;
			if (map->crd[i][j] == 'P')
				elt.p += 1;
			j++;
		}
		i++;
	}
	if (elt.e < 1 || elt.c < 1 || elt.p < 1)
		error_obj_map(map, elt);
}

void	verif_acces_collectible(t_map *map)
{
	
}

void	verif_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->crd && map->crd[0][i])
	{
		if (map->crd[0][i] != '1')
			error_wall_map(map->crd);
	}
	i = 0;
	while (map->crd && map->crd[i][0])
	{
		if (map->crd[i][0] != '1')
			error_wall_map(map->crd);
	}
	i -= 1;
	j = 0;
	while (map && map->crd[i][j])
	{
		if (map->crd[i][j] != '1')
			error_wall_map(map->crd);
	}
	verif_obj_map(map);
	verif_acces_collectible(map);
}
