/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:49:17 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/24 19:56:43 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_win(t_data *data, int move_y, int move_x)
{
	int	y;
	int	x;

	x = data->map->p_x + move_x;
	y = data->map->p_y + move_y;
	data->map->crd[y][x] = data->map->pre_tile;
	data->map->pre_tile = data->map->crd[y][x];
	data->map->crd[y][x] = 'P';
	mlx_destroy_image
	data->map->p_x = x;
	data->map->p_y = y;
}

void	move_player(t_data *data, int move_y, int move_x)
{
	int y;
	int x;

	y = data->map->p_y + move_y;
	x = data->map->p_x + move_x;
	if (data->map->crd[y][x] == '1')
		return ;
	if (data->map->crd[y][x] == '0' || data->map->crd[y][x] == 'C')
	{
		data->map->crd[y][x] = data->map->pre_tile;
		data->map->pre_tile = data->map->crd[y][x + 1];
		data->map->crd[y][x] = 'P';
		data->map->p_x = x;
		data->map->p_y = y;
		if (data->map->crd[y][x + 1] == 'C')
			data->map->c -= 1;
	}
	else if (data->map->crd[y][x + 1] == 'E' && data->map->c == 0)
	{
		game_win(data, move_y, move_x);
	}
}
