/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_of_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:47:39 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/27 01:31:52 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	view_player(t_data *data, int y, int x)
{
	if (x == 1)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->player_right, (data->map->p_x + x) * 32,
			(data->map->p_y + y) * 32);
	else if (x == -1)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->player_left, (data->map->p_x + x) * 32,
			(data->map->p_y + y) * 32);
	else if (y == 1)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->player_bottom, (data->map->p_x + x) * 32,
			(data->map->p_y + y) * 32);
	else if (y == -1)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->player_top, (data->map->p_x + x) * 32,
			(data->map->p_y + y) * 32);
}
