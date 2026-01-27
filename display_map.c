/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:44:04 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/27 01:29:43 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_win *win, char c, int y, int x)
{
	if (c == '1')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->wall, x
			* win->width_img, y * win->height_img);
	if (c == '0')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->floor, x
			* win->width_img, y * win->height_img);
	if (c == 'P')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->player_bottom,
			x * win->width_img, y * win->height_img);
	if (c == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->collectible, x
			* win->width_img, y * win->height_img);
	if (c == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->exit, x
			* win->width_img, y * win->height_img);
	if (c == 'S')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->enemie, x
			* win->width_img, y * win->height_img);
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
			display_map(win, map->crd[y][x], y, x);
			x++;
		}
		y++;
	}
}
