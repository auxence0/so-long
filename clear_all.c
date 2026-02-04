/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:17:25 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/04 13:34:37 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_players_collectibles(t_win *win)
{
	if (win->player[0])
		mlx_destroy_image(win->mlx_ptr, win->player[0]);
	if (win->player[1])
		mlx_destroy_image(win->mlx_ptr, win->player[1]);
	if (win->player[2])
		mlx_destroy_image(win->mlx_ptr, win->player[2]);
	if (win->player[3])
		mlx_destroy_image(win->mlx_ptr, win->player[3]);
	if (win->collectible[0])
		mlx_destroy_image(win->mlx_ptr, win->collectible[0]);
	if (win->collectible[1])
		mlx_destroy_image(win->mlx_ptr, win->collectible[1]);
	if (win->collectible[2])
		mlx_destroy_image(win->mlx_ptr, win->collectible[2]);
	if (win->collectible[3])
		mlx_destroy_image(win->mlx_ptr, win->collectible[3]);
	if (win->collectible[4])
		mlx_destroy_image(win->mlx_ptr, win->collectible[4]);
	if (win->collectible[5])
		mlx_destroy_image(win->mlx_ptr, win->collectible[5]);
}

void	destroy_img(t_win *win)
{
	destroy_players_collectibles(win);
	if (win->patrol[0])
		mlx_destroy_image(win->mlx_ptr, win->patrol[0]);
	if (win->patrol[1])
		mlx_destroy_image(win->mlx_ptr, win->patrol[1]);
	if (win->patrol[2])
		mlx_destroy_image(win->mlx_ptr, win->patrol[2]);
	if (win->wall)
		mlx_destroy_image(win->mlx_ptr, win->wall);
	if (win->floor)
		mlx_destroy_image(win->mlx_ptr, win->floor);
	if (win->exit[0])
		mlx_destroy_image(win->mlx_ptr, win->exit[0]);
	if (win->exit[1])
		mlx_destroy_image(win->mlx_ptr, win->exit[1]);
	if (win->exit[2])
		mlx_destroy_image(win->mlx_ptr, win->exit[2]);
}

void	clear_all(t_win *win, t_map *map)
{
	destroy_img(win);
	if (win->mlx_ptr && win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
		mlx_destroy_display(win->mlx_ptr);
	if (win->mlx_ptr)
		free(win->mlx_ptr);
	free_tab(map->crd);
	if (map->movement)
		free(map->movement);
}

int	close_win(t_data *data)
{
	clear_all(data->win, data->map);
	if (data)
		free(data);
	exit(0);
}
