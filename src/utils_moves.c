/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:47:39 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/04 13:41:26 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	view_player(t_data *data, int y, int x)
{
	if (x == 1)
		data->map->index_player = 2;
	else if (x == -1)
		data->map->index_player = 3;
	else if (y == 1)
		data->map->index_player = 0;
	else if (y == -1)
		data->map->index_player = 1;
}

char	*str_movement(t_data *data, int y, int x)
{
	char	*str;

	if (data->map->movement)
		free(data->map->movement);
	str = ft_itoa(data->map->moves);
	if (!str)
		close_win(data);
	str = ft_strjoin_free_s2("move : ", str);
	if (!str)
		close_win(data);
	if (x == 1)
		str = ft_strjoin_free_s2("right, ", str);
	else if (x == -1)
		str = ft_strjoin_free_s2("left, ", str);
	else if (y == 1)
		str = ft_strjoin_free_s2("down, ", str);
	else if (y == -1)
		str = ft_strjoin_free_s2("up, ", str);
	if (!str)
		close_win(data);
	return (str);
}
