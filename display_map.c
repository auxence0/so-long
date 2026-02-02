/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:44:04 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/30 18:25:02 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_right_left(t_win *win, t_map *map, int y, int x)
{
	if (map->index_enemie == 0)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->enemie[map->index_enemie], x * win->width_img, y
			* win->height_img);
	else
	{
		if (x < map->p_x)
		{
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
				win->enemie[1], x * win->width_img, y
				* win->height_img);
		}
		else
		{
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
				win->enemie[2], x * win->width_img, y
				* win->height_img);
		}
	}
}

void	display_map(t_win *win, t_map *map, int y, int x)
{
	char	c;

	c = map->crd[y][x];
	if (c == '0')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->floor, x
			* win->width_img, y * win->height_img);
	if (c == '1')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->wall, x
			* win->width_img, y * win->height_img);
	if (c == 'P')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->player[map->index_player], x * win->width_img, y
			* win->height_img);
	if (c == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->collectible[map->index_coll], x * win->width_img, y
			* win->height_img);
	if (c == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->exit[map->index_exit], x * win->width_img, y
			* win->height_img);
	if (c == 'S')
		check_right_left(win, map, y, x);
}

void	render_map(t_win *win, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->crd[y])
	{
		x = 0;
		while (map->crd[y][x])
		{
			display_map(win, map, y, x);
			x++;
		}
		y++;
	}
}
