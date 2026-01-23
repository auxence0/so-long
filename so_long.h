/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:17:00 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/22 18:36:48 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_win;

typedef struct s_map
{
	int		width;
	int		height;
	int		zoom;
	char	**crd;
}			t_map;

int		open_file(char *file);
void	malloc_map(t_map *map, char *file);
void	free_tab(char **tab);

#endif