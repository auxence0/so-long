/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_of_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:47:39 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/30 16:36:23 by asauvage         ###   ########.fr       */
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
