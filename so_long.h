/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:17:00 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/30 19:05:16 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		width;
	int		height;
	void	*wall;
	void	*floor;
	void	*player[4];
	void	*enemie[3];
	void	*collectible[6];
	void	*exit[3];
	int		width_img;
	int		height_img;
}			t_win;

typedef struct s_map
{
	int		width;
	int		height;
	int		zoom;
	int		p_x;
	int		p_y;
	int		c;
	int		e;
	int		p;
	int		s;
	int		verif_c;
	int		verif_e;
	int		moves;
	long	frame;
	int		index_player;
	int		index_coll;
	int		index_exit;
	int		index_enemie;
	int		end;
	char	pre_tile;
	char	*movement;
	char	**crd;
	char	**tmp_map;
}			t_map;

typedef struct s_data
{
	t_win	*win;
	t_map	*map;
}			t_data;

int			open_file(char *file, t_map *map);
int			close_win(t_data *data);
int			handle_escape(int keycode, t_data *data);
char		*ft_strjoin_free_s2(char const *s1, char *s2);
char		*str_movement(t_data *data, int y, int x);
char		**ft_strstrdup(char **tab, t_map *map);
void		malloc_height(t_map *map, char *file);
void		flood_fill(t_map *map, int y, int x);
void		malloc_lines(t_map *map, char *file);
void		free_tab(char **tab);
void		start_player(t_map *map);
void		verif_walls(t_map *map);
void		verif_obj_map(t_map *map);
void		verif_acces_collectible(t_map *map, int y, int x);
void		init_win(t_win *win, t_map *map, char *file);
void		render_map(t_win *win, t_map *map);
void		my_mlx_hook(t_win *win, t_map *map);
void		move_player(t_data *data, int move_y, int move_x);
void		add_obj(char c, t_map *map);
void		view_player(t_data *data, int x, int y);

#endif