/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_of_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:47:39 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/25 23:51:14 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	view_player(t_data *data, int x, int y)
{
	if (x == 1)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->player_right, (x + 3) * 32, (y + 3) * 32);
	else if (x == -1)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->player_left, (x + 3) * 32, (y + 3) * 32);
	else if (y == 1)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->player_bottom, (x + 3) * 32, (y + 3) * 32);
	else if (y == -1)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->player_top, (x + 3) * 32, (y + 3) * 32);
}