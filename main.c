/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:16:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/30 16:06:08 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct_file(char *file)
{
	int	i;
	int	res;

	i = 0;
	while (file && file[i + 4])
		i++;
	res = ft_strncmp(&file[i], ".ber", 4);
	return (res);
}

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

	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&win, sizeof(t_win));
	if (ac != 2 || ft_strlen(av[1]) < 5 || correct_file(av[1]))
	{
		ft_putstr_fd("U need to give one arg : file.ber\n", 2);
		return (1);
	}
	parse_map(&map, av[1]);
	init_win(&win, &map, av[1]);
	render_map(&win, &map);
	my_mlx_hook(&win, &map);
	mlx_loop(win.mlx_ptr);
	return (0);
}
