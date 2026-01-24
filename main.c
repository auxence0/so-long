/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:16:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/24 19:18:36 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_map *map, char *file)
{
	malloc_height(map, file);
	malloc_lines(map, file);
	verif_walls(map, 0, 0);
	verif_obj_map(map);
	start_player(map);
	map->tmp_map = ft_strstrdup(map->crd, map);
	verif_acces_collectible(map, map->p_y, map->p_x);
	free_tab(map->tmp_map);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_win	win;

	if (ac != 2)
	{
		ft_putstr_fd("U need to give one arg\n", 2);
		return (1);
	}
	parse_map(&map, av[1]);
	init_win(&win, &map, av[1]);
	render_map(&win, &map);
	my_mlx_hook(&win, &map);
	mlx_loop(win.mlx_ptr);
	return (0);
}
