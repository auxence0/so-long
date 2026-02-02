/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:49:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/30 18:24:26 by asauvage         ###   ########.fr       */
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
	ft_putstr_fd("Error : Failed to open window\n", 2);
	exit(1);
}

void	err_texture(t_win *win)
{
	if (!win->wall)
		ft_putstr_fd("Error : Wall failed to load\n", 2);
	if (!win->collectible[0] || !win->collectible[1] || !win->collectible[2]
		|| !win->collectible[3] || !win->collectible[4] || !win->collectible[5])
		ft_putstr_fd("Error : Collectible failed to load\n", 2);
	if (!win->exit[0] || !win->exit[1] || !win->exit[2])
		ft_putstr_fd("Error : Exit failed to load\n", 2);
	if (!win->floor)
		ft_putstr_fd("Error : Floor failed to load\n", 2);
	if (!win->player[0] || !win->player[1] || !win->player[2]
		|| !win->player[3])
		ft_putstr_fd("Error : Failed to load player_bottom\n", 2);
	if (!win->enemie[0] || !win->enemie[1] || !win->enemie[2])
		ft_putstr_fd("Error : Failed to load enemie\n", 2);
	if (!win->wall || !win->collectible[0] || !win->collectible[1]
		|| !win->collectible[2] || !win->collectible[3] || !win->exit[0]
		|| !win->exit[1] || !win->exit[2] || !win->player[0] || !win->player[1]
		|| !win->player[2] || !win->player[3] || !win->enemie[0]
		|| !win->enemie[1] || !win->enemie[2] || !win->floor)
		exit(1);
}

void	load_players_collectibles(t_win *win)
{
	win->player[0] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/mario_bottom.xpm", &win->width_img, &win->height_img);
	win->player[1] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/mario_top.xpm", &win->width_img, &win->height_img);
	win->player[2] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/mario_right.xpm", &win->width_img, &win->height_img);
	win->player[3] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/mario_left.xpm", &win->width_img, &win->height_img);
	win->collectible[0] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_front.xpm", &win->width_img, &win->height_img);
	win->collectible[1] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_semi_right.xpm", &win->width_img,
			&win->height_img);
	win->collectible[2] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_right.xpm", &win->width_img, &win->height_img);
	win->collectible[3] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_profile.xpm", &win->width_img,
			&win->height_img);
	win->collectible[4] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_left.xpm", &win->width_img, &win->height_img);
	win->collectible[5] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_semi_left.xpm", &win->width_img,
			&win->height_img);
}

void	texture_img(t_win *win)
{
	load_players_collectibles(win);
	win->wall = mlx_xpm_file_to_image(win->mlx_ptr, "texture/wall.xpm",
			&win->width_img, &win->height_img);
	win->floor = mlx_xpm_file_to_image(win->mlx_ptr, "texture/floor.xpm",
			&win->width_img, &win->height_img);
	win->enemie[0] = mlx_xpm_file_to_image(win->mlx_ptr, "texture/Bowser.xpm",
			&win->width_img, &win->height_img);
	win->enemie[1] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/Bowser_right.xpm", &win->width_img, &win->height_img);
	win->enemie[2] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/Bowser_left.xpm", &win->width_img, &win->height_img);
	win->exit[0] = mlx_xpm_file_to_image(win->mlx_ptr, "texture/tube_red.xpm",
			&win->width_img, &win->height_img);
	win->exit[1] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/tube_yellow.xpm", &win->width_img, &win->height_img);
	win->exit[2] = mlx_xpm_file_to_image(win->mlx_ptr, "texture/tube_green.xpm",
			&win->width_img, &win->height_img);
	err_texture(win);
}

void	init_win(t_win *win, t_map *map, char *file)
{
	int	max_width;
	int	max_height;

	win->height = (map->height) * 32;
	win->width = (map->width) * 32;
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		err_init(win, map);
	mlx_get_screen_size(win->mlx_ptr, &max_width, &max_height);
	if (win->height > max_height - 64 || win->width > max_width)
	{
		ft_putstr_fd("Error : The map is to wide\n", 2);
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
