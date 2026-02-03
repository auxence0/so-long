/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:49:17 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/30 18:17:03 by asauvage         ###   ########.fr       */
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
	view_player(data, move_y, move_x);
	data->map->p_y = y;
	data->map->p_x = x;
	data->map->pre_tile = 'E';
	data->map->moves += 1;
	data->map->crd[y][x] = 'P';
	render_map(data->win, data->map);
	data->map->movement = str_movement(data, move_y, move_x);
	mlx_string_put(data->win->mlx_ptr, data->win->win_ptr, 5, 20, 0x00FF00,
		data->map->movement);
	ft_printf("%s\n", data->map->movement);
}

void	game_win(t_data *data, int move_y, int move_x)
{
	int	y;
	int	x;

	x = data->map->p_x + move_x;
	y = data->map->p_y + move_y;
	view_player(data, 1, 0);
	data->map->moves += 1;
	data->map->crd[y][x] = 'P';
	data->map->pre_tile = 'E';
	render_map(data->win, data->map);
	data->map->movement = str_movement(data, move_y, move_x);
	mlx_string_put(data->win->mlx_ptr, data->win->win_ptr, 5, 20, 0x00FF00,
		data->map->movement);
	data->map->end = 1;
	ft_printf("%s\n", data->map->movement);
	mlx_string_put(data->win->mlx_ptr, data->win->win_ptr, data->win->width / 2,
		data->win->height / 2, 0x00FF00, "YOU WIN!");
	mlx_hook(data->win->win_ptr, 2, 1L << 0, handle_escape, data);
	mlx_hook(data->win->win_ptr, 17, 0, close_win, data);
}

void	take_collectible(t_data *data, int move_y, int move_x)
{
	int	y;
	int	x;

	y = data->map->p_y + move_y;
	x = data->map->p_x + move_x;
	if (data->map->crd[y][x] == 'C')
		data->map->c -= 1;
	view_player(data, move_y, move_x);
	data->map->p_y = y;
	data->map->p_x = x;
	data->map->moves += 1;
	data->map->pre_tile = '0';
	data->map->crd[y][x] = 'P';
	if (data->map->c == data->map->verif_c / 2)
		data->map->index_exit = 1;
	if (data->map->c == 0)
		data->map->index_exit = 2;
	render_map(data->win, data->map);
	data->map->movement = str_movement(data, move_y, move_x);
	mlx_string_put(data->win->mlx_ptr, data->win->win_ptr, 5, 20, 0x00FF00,
		data->map->movement);
	ft_printf("%s\n", data->map->movement);
}

void	game_lose(t_data *data)
{
	data->map->end = 1;
	data->map->index_enemie = 1;
	render_map(data->win, data->map);
	mlx_string_put(data->win->mlx_ptr, data->win->win_ptr, 5, 20, 0x00FF00,
		data->map->movement);
	mlx_string_put(data->win->mlx_ptr, data->win->win_ptr, data->win->width
		/ 2, data->win->height / 2, 0xFF00FB, "YOU LOSE!");
	mlx_hook(data->win->win_ptr, 2, 1L << 0, handle_escape, data);
	mlx_hook(data->win->win_ptr, 17, 0, close_win, data);
}

void	move_player(t_data *data, int mv_y, int mv_x)
{
	int	y;
	int	x;

	y = data->map->p_y;
	x = data->map->p_x;
	if (data->map->crd[y + mv_y][x + mv_x] == '1')
		return ;
	if (data->map->crd[y + mv_y][x + mv_x] == 'S')
		game_lose(data);
	data->map->crd[y][x] = data->map->pre_tile;
	if (data->map->crd[y + mv_y][x + mv_x] == '0' || data->map->crd[y + mv_y][x
		+ mv_x] == 'C')
		take_collectible(data, mv_y, mv_x);
	else if (data->map->crd[y + mv_y][x + mv_x] == 'E' && data->map->c == 0)
		game_win(data, mv_y, mv_x);
	else if (data->map->crd[y + mv_y][x + mv_x] == 'E')
		go_over_exit(data, mv_y, mv_x);
}
