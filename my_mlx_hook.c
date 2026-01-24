/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:54:15 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/24 19:04:23 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_data *data)
{
	if (data->win->wall)
		mlx_destroy_image(data->win->mlx_ptr, data->win->wall);
	if (data->win->floor)
		mlx_destroy_image(data->win->mlx_ptr, data->win->floor);
	if (data->win->player)
		mlx_destroy_image(data->win->mlx_ptr, data->win->player);
	if (data->win->exit)
		mlx_destroy_image(data->win->mlx_ptr, data->win->exit);
	if (data->win->collectible)
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible);
}

int	close_win(t_data *data)
{
	destroy_img(data);
	mlx_destroy_image(data->win->mlx_ptr, data->win->img);
	mlx_destroy_window(data->win->mlx_ptr, data->win->win_ptr);
	mlx_destroy_display(data->win->mlx_ptr);
	free(data->win->mlx_ptr);
	free_tab(data->map->crd);
	free(data);
	exit(0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_win(data);
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
	mlx_hook(win->win_ptr, 17, 0, close_win, data);
	mlx_hook(win->win_ptr, 2, 1L << 0, handle_keypress, data);
}
