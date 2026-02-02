/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:56:03 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/02 11:56:05 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_players_collectibles(t_data *data)
{
	if (data->win->player[0])
		mlx_destroy_image(data->win->mlx_ptr, data->win->player[0]);
	if (data->win->player[1])
		mlx_destroy_image(data->win->mlx_ptr, data->win->player[1]);
	if (data->win->player[2])
		mlx_destroy_image(data->win->mlx_ptr, data->win->player[2]);
	if (data->win->player[3])
		mlx_destroy_image(data->win->mlx_ptr, data->win->player[3]);
	if (data->win->collectible[0])
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible[0]);
	if (data->win->collectible[1])
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible[1]);
	if (data->win->collectible[2])
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible[2]);
	if (data->win->collectible[3])
		mlx_destroy_image(data->win->mlx_ptr, data->win->collectible[3]);
}

void	destroy_img(t_data *data)
{
	destroy_players_collectibles(data);
	if (data->win->enemie[0])
		mlx_destroy_image(data->win->mlx_ptr, data->win->enemie[0]);
	if (data->win->enemie[1])
		mlx_destroy_image(data->win->mlx_ptr, data->win->enemie[1]);
	if (data->win->enemie[2])
		mlx_destroy_image(data->win->mlx_ptr, data->win->enemie[2]);
	if (data->win->wall)
		mlx_destroy_image(data->win->mlx_ptr, data->win->wall);
	if (data->win->floor)
		mlx_destroy_image(data->win->mlx_ptr, data->win->floor);
	if (data->win->exit[0])
		mlx_destroy_image(data->win->mlx_ptr, data->win->exit[0]);
	if (data->win->exit[1])
		mlx_destroy_image(data->win->mlx_ptr, data->win->exit[1]);
	if (data->win->exit[2])
		mlx_destroy_image(data->win->mlx_ptr, data->win->exit[2]);
}

int	close_win(t_data *data)
{
	destroy_img(data);
	if (data->win && data->win->win_ptr)
		mlx_destroy_window(data->win->mlx_ptr, data->win->win_ptr);
	if (data->win->mlx_ptr)
	{
		mlx_destroy_display(data->win->mlx_ptr);
		free(data->win->mlx_ptr);
	}
	free_tab(data->map->crd);
	if (data->map->movement)
		free(data->map->movement);
	free(data);
	exit(0);
}