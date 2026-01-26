/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:49:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/26 13:48:58 by asauvage         ###   ########.fr       */
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
	ft_putstr_fd("Failed to open window\n", 2);
	exit(1);
}

void	err_texture(t_win *win)
{
	if (!win->wall)
		ft_putstr_fd("Wall failed to load\n", 2);
	if (!win->collectible)
		ft_putstr_fd("Collectible failed to load\n", 2);
	if (!win->exit)
		ft_putstr_fd("Exit failed to load\n", 2);
	if (!win->floor)
		ft_putstr_fd("Floor failed to load\n", 2);
	if (!win->player_bottom)
		ft_putstr_fd("Failed to load player_bottom\n", 2);
	if (!win->player_top)
		ft_putstr_fd("Failed to load player_top\n", 2);
	if (!win->player_right)
		ft_putstr_fd("Failed to load player_right\n", 2);
	if (!win->player_left)
		ft_putstr_fd("Failed to load player_left\n", 2);
	if (!win->enemie)
		ft_putstr_fd("Failed to load enemie", 2);
	if (!win->wall || !win->collectible || !win->exit || !win->player_bottom
		|| !win->player_top || !win->player_right || !win->player_left
		|| !win->enemie || !win->floor)
		exit(1);
}

void	texture_img(t_win *win)
{
	win->wall = mlx_xpm_file_to_image(win->mlx_ptr, "texture/wall.xpm",
			&win->width_img, &win->height_img);
	win->floor = mlx_xpm_file_to_image(win->mlx_ptr, "texture/floor.xpm",
			&win->width_img, &win->height_img);
	win->player_bottom = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/player_bottom.xpm", &win->width_img, &win->height_img);
	win->player_top = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/player_top.xpm", &win->width_img, &win->height_img);
	win->player_right = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/player_right.xpm", &win->width_img, &win->height_img);
	win->player_left = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/player_left.xpm", &win->width_img, &win->height_img);
	win->enemie = mlx_xpm_file_to_image(win->mlx_ptr, "texture/enemie.xpm",
			&win->width_img, &win->height_img);
	win->collectible = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible.xpm", &win->width_img, &win->height_img);
	win->exit = mlx_xpm_file_to_image(win->mlx_ptr, "texture/exit.xpm",
			&win->width_img, &win->height_img);
	err_texture(win);
}

void	init_win(t_win *win, t_map *map, char *file)
{
	int	max_width;
	int	max_height;

	win->height = (map->height + 6) * 32;
	win->width = (map->width + 6) * 32;
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		err_init(win, map);
	mlx_get_screen_size(win->mlx_ptr, &max_width, &max_height);
	if (win->height > max_height || win->width > max_width)
	{
		ft_putstr_fd("The map is to wide\n", 2);
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		free_tab(map->crd);
		exit(1);
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, win->height, file);
	if (!win->win_ptr)
		err_init(win, map);
	texture_img(win);
}
