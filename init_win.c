/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:49:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/24 16:15:20 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_init(t_win *win, t_map *map)
{
	if (win->mlx_ptr && win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
	{
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
	}
	free_tab(map->crd);
	free_tab(map->tmp_map);
	ft_putstr_fd("Failed to open window\n", 2);
	exit(1);
}

void	init_win(t_win *win, t_map *map, char *file)
{
	win->height = (map->height + 6) * 32;
	win->width = (map->width + 6) * 32;
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		err_init_win(win, map);
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, win->height, file);
	if (!win->win_ptr)
		err_init_win(win, map);
}