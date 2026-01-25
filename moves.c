/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:49:17 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/25 17:38:15 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_over_exit(t_data *data, int move_y, int move_x)
{
	int	y;
	int	x;

	y = data->map->p_y + move_y;
	x = data->map->p_x + move_x;
	if (data->map->pre_tile != 'E')
		data->map->crd[data->map->p_y][data->map->p_x] = '0';
	mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
		data->win->player, (x + 3) * 32, (y + 3) * 32);
	data->map->p_y = y;
	data->map->p_x = x;
	data->map->pre_tile = 'E';
	data->map->moves += 1;
	ft_printf("move : %d\n", data->map->moves);
}

void	game_win(t_data *data, int move_y, int move_x)
{
	int	y;
	int	x;

	x = data->map->p_x + move_x;
	y = data->map->p_y + move_y;
	mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
		data->win->player, (x + 3) * 32, (y + 3) * 32);
	data->map->p_y = y;
	data->map->p_x = x;
	data->map->moves += 1;
	data->map->pre_tile = '0';
	ft_printf("move : %d\n", data->map->moves);
	close_win(data);
}

void	take_collectible(t_data *data, int move_y, int move_x)
{
	int	y;
	int	x;

	y = data->map->p_y + move_y;
	x = data->map->p_x + move_x;
	if (data->map->pre_tile != 'E')
		data->map->crd[data->map->p_y][data->map->p_x] = '0';
	if (data->map->crd[y][x] == 'C')
		data->map->c -= 1;
	mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
		data->win->player, (x + 3) * 32, (y + 3) * 32);
	data->map->crd[y][x] = '0';
	data->map->p_y = y;
	data->map->p_x = x;
	data->map->moves += 1;
	data->map->pre_tile = '0';
	ft_printf("move : %d\n", data->map->moves);
}

void	move_player(t_data *data, int mv_y, int mv_x)
{
	int	y;
	int	x;

	y = data->map->p_y;
	x = data->map->p_x;
	ft_printf("y : %d, x : %d\n", y, x);
	ft_printf("pre_tile : %c case : %c\n", data->map->pre_tile, data->map->crd[y + mv_y][x + mv_x]);
	if (data->map->crd[y + mv_y][x + mv_x] == '1')
		return ;
	if (data->map->pre_tile == '0')
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->floor, (x + 3) * 32, (y + 3) * 32);
	else
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
			data->win->exit, (x + 3) * 32, (y + 3) * 32);
	if (data->map->crd[y + mv_y][x + mv_x] == '0' || data->map->crd[y + mv_y][x
		+ mv_x] == 'C')
		take_collectible(data, mv_y, mv_x);
	else if (data->map->crd[y + mv_y][x + mv_x] == 'E' && data->map->c == 0)
		game_win(data, mv_y, mv_x);
	else if (data->map->crd[y + mv_y][x + mv_x] == 'E')
		go_over_exit(data, mv_y, mv_x);
}
