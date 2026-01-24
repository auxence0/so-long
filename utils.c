/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:24:17 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/24 15:45:41 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_strstrdup(char **tab, t_map *map)
{
	char	**res;
	int		i;

	res = malloc((sizeof(char *)) * (map->height + 1));
	if (res == NULL)
		exit(1);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
		{
			free_tab(res);
			exit(1);
		}
		i++;
	}
	res[i] = 0;
	return (res);
}

int	flood_fill(t_map *map, int y, int x)
{
	int	count;

	count = 0;
	if (x < 0 || x > map->width - 1 || y < 0 || y > map->height - 1)
		return (0);
	if (map->tmp_map[y][x] == '1' || map->tmp_map[y][x] == 'K')
		return (0);
	if (map->tmp_map[y][x] == 'C')
		count += 1;
	map->tmp_map[y][x] = 'K';
	count += flood_fill(map, y - 1, x);
	count += flood_fill(map, y + 1, x);
	count += flood_fill(map, y, x - 1);
	count += flood_fill(map, y, x + 1);
	return (count);
}

void	start_player(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->p_x = 0;
	map->p_y = 0;
	while (map->crd[y])
	{
		x = 0;
		while (map->crd[y][x])
		{
			if (map->crd[y][x] == 'P')
			{
				map->p_x = x;
				map->p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
