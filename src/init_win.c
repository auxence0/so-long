/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:49:45 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/13 16:18:29 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_texture(t_win *win, t_map *map)
{
	if (!win->wall)
		ft_printf("Error : Wall failed to load\n");
	if (!win->collectible[0] || !win->collectible[1] || !win->collectible[2]
		|| !win->collectible[3] || !win->collectible[4] || !win->collectible[5])
		ft_printf("Error : Collectible failed to load\n");
	if (!win->exit[0] || !win->exit[1] || !win->exit[2])
		ft_printf("Error : Exit failed to load\n");
	if (!win->floor)
		ft_printf("Error : Floor failed to load\n");
	if (!win->player[0] || !win->player[1] || !win->player[2]
		|| !win->player[3])
		ft_printf("Error : Failed to load player\n");
	if (!win->patrol[0] || !win->patrol[1] || !win->patrol[2])
		ft_printf("Error : Failed to load enemie\n");
	if (!win->wall || !win->collectible[0] || !win->collectible[1]
		|| !win->collectible[2] || !win->collectible[3] || !win->exit[0]
		|| !win->exit[1] || !win->exit[2] || !win->player[0] || !win->player[1]
		|| !win->player[2] || !win->player[3] || !win->patrol[0]
		|| !win->patrol[1] || !win->patrol[2] || !win->floor)
		clear_all(win, map);
}

void	load_players_collectibles(t_win *win)
{
	win->player[0] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/mario_bottom_64.xpm", &win->width_img, &win->height_img);
	win->player[1] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/mario_top_64.xpm", &win->width_img, &win->height_img);
	win->player[2] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/mario_right_64.xpm", &win->width_img, &win->height_img);
	win->player[3] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/mario_left_64.xpm", &win->width_img, &win->height_img);
	win->collectible[0] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_front_64.xpm", &win->width_img, &win->height_img);
	win->collectible[1] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_semi_right_64.xpm", &win->width_img,
			&win->height_img);
	win->collectible[2] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_right_64.xpm", &win->width_img, &win->height_img);
	win->collectible[3] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_profile_64.xpm", &win->width_img,
			&win->height_img);
	win->collectible[4] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_left_64.xpm", &win->width_img, &win->height_img);
	win->collectible[5] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/collectible_semi_left_64.xpm", &win->width_img,
			&win->height_img);
}

void	load_texture_img(t_win *win, t_map *map)
{
	load_players_collectibles(win);
	win->wall = mlx_xpm_file_to_image(win->mlx_ptr, "texture/wall_64.xpm",
			&win->width_img, &win->height_img);
	win->floor = mlx_xpm_file_to_image(win->mlx_ptr, "texture/floor_64.xpm",
			&win->width_img, &win->height_img);
	win->patrol[0] = mlx_xpm_file_to_image(win->mlx_ptr, "texture/Bowser_64.xpm",
			&win->width_img, &win->height_img);
	win->patrol[1] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/Bowser_right_64.xpm", &win->width_img, &win->height_img);
	win->patrol[2] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/Bowser_left_64.xpm", &win->width_img, &win->height_img);
	win->exit[0] = mlx_xpm_file_to_image(win->mlx_ptr, "texture/tube_red_64.xpm",
			&win->width_img, &win->height_img);
	win->exit[1] = mlx_xpm_file_to_image(win->mlx_ptr,
			"texture/tube_yellow_64.xpm", &win->width_img, &win->height_img);
	win->exit[2] = mlx_xpm_file_to_image(win->mlx_ptr, "texture/tube_green_64.xpm",
			&win->width_img, &win->height_img);
	err_texture(win, map);
}

void	err_mess(t_win *win, t_map *map, int max_height, int max_width)
{
	if (!win->mlx_ptr)
	{
		ft_printf("Error : Failed to init mlx\n");
		clear_all(win, map);
		exit (1);
	}
	else if (win->height > max_height - 64 || win->width > max_width)
	{
		ft_printf("Error : The map is too wide");
		clear_all(win, map);
		exit(1);
	}
	else if (!win->win_ptr)
	{
		ft_printf("Error : Failed to init mlx\n");
		clear_all(win, map);
		exit (1);
	}
}

void	init_win(t_win *win, t_map *map, char *file)
{
	int	max_width;
	int	max_height;

	win->height = (map->height) * 64;
	win->width = (map->width) * 64;
	max_width = 0;
	max_height = 0;
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		err_mess(win, map, max_height, max_width);
	mlx_get_screen_size(win->mlx_ptr, &max_width, &max_height);
	if (win->height > max_height - 64 || win->width > max_width)
		err_mess(win, map, max_height, max_width);
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, win->height, file);
	if (!win->win_ptr)
		err_mess(win, map, max_height, max_width);
}
