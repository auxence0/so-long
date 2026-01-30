/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:54:15 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/30 19:04:48 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_data *data)
{
	if (data->win->wall)
		mlx_destroy_image(data->win->mlx_ptr, data->win->wall);
	if (data->win->floor)
		mlx_destroy_image(data->win->mlx_ptr, data->win->floor);
	if (data->win->player[0])
		mlx_destroy_image(data->win->mlx_ptr, data->win->player[0]);
	if (data->win->player[1])
		mlx_destroy_image(data->win->mlx_ptr, data->win->player[1]);
	if (data->win->player[2])
		mlx_destroy_image(data->win->mlx_ptr, data->win->player[2]);
	if (data->win->player[3])
		mlx_destroy_image(data->win->mlx_ptr, data->win->player[3]);
	if (data->win->exit[0])
		mlx_destroy_image(data->win->mlx_ptr, data->win->exit[0]);
	if (data->win->exit[1])
		mlx_destroy_image(data->win->mlx_ptr, data->win->exit[1]);
	if (data->win->collectible[0])
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible[0]);
	if (data->win->collectible[1])
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible[1]);
	if (data->win->collectible[2])
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible[2]);
	if (data->win->collectible[3])
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible[3]);
}

int	close_win(t_data *data)
{
	destroy_img(data);
	mlx_destroy_window(data->win->mlx_ptr, data->win->win_ptr);
	mlx_destroy_display(data->win->mlx_ptr);
	free(data->win->mlx_ptr);
	free_tab(data->map->crd);
	if (data->map->movement)
		free(data->map->movement);
	free(data);
	exit(0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		move_player(data, -1, 0);
	if (keycode == 115 || keycode == 65364)
		move_player(data, 1, 0);
	if (keycode == 97 || keycode == 65361)
		move_player(data, 0, -1);
	if (keycode == 100 || keycode == 65363)
		move_player(data, 0, 1);
	if (keycode == 65307)
		close_win(data);
	return (0);
}

int	animation_collectible(t_data *data)
{
	if (data->map->frame++ > 40000)
	{
		data->map->frame = 0;
		data->map->index_coll = (data->map->index_coll + 1) % 4;
		render_map(data->win, data->map);
		if (data->map->movement)
			mlx_string_put(data->win->mlx_ptr, data->win->win_ptr, 5, 20,
				0x00FF00, data->map->movement);
	}
	return (0);
}

void	my_mlx_hook(t_win *win, t_map *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->win = win;
	data->map = map;
	data->map->pre_tile = '0';
	mlx_hook(win->win_ptr, 17, 0, close_win, data);
	mlx_hook(win->win_ptr, 2, 1L << 0, handle_keypress, data);
	mlx_loop_hook(win->mlx_ptr, animation_collectible, data);
}
