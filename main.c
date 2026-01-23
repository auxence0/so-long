/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:16:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/22 18:44:58 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_map(t_map *map, char *file)
{
	malloc_map(map, file);
}


int	main(int ac, char **av)
{
	t_map	map;
	//t_win	win;

	if (ac != 2)
	{
		ft_putstr_fd("U need to give one arg\n", 2);
		return (1);
	}
	size_map(&map, av[1]);
	// read_z_axis(&map, av[1]);
	// init_win(&win, &map, av);
	// creat_map(&map, &win, av[1]);
	// mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img, 0, 0);
	// my_mlx_hook(&win);
	// mlx_loop(win.mlx_ptr);
	return (0);
}