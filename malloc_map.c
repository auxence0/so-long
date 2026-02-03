/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:31:59 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/30 19:03:32 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: %s", strerror(errno), file);
		free_tab(map->crd);
		exit(1);
	}
	return (fd);
}

int	verif_len_line(char **map)
{
	size_t	pre_len;
	int		y;

	y = 1;
	pre_len = ft_strlen(map[0]);
	while (map && map[y])
	{
		if (pre_len != ft_strlen(map[y]))
		{
			ft_printf("Error : the line sizes are not equal\n");
			free_tab(map);
			exit(1);
		}
		pre_len = ft_strlen(map[y]);
		y++;
	}
	return (pre_len);
}

void	check_malloc_line(t_map *map, char *line, int fd)
{
	if (!line)
	{
		free_tab(map->crd);
		close(fd);
		exit(1);
	}
}

void	malloc_lines(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open_file(file, map);
	i = -1;
	line = get_next_line(fd);
	while (++i < map->height)
	{
		check_malloc_line(map, line, fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->crd[i] = ft_strdup(line);
		free(line);
		if (!map->crd[i])
		{
			free_tab(map->crd);
			exit(1);
		}
		line = get_next_line(fd);
	}
	map->width = verif_len_line(map->crd);
	close(fd);
}

void	malloc_height(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open_file(file, map);
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			break ;
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	if (map->height < 3)
	{
		ft_printf("Error : You need at least 3 lines to create a map.\n");
		close(fd);
		exit(1);
	}
	map->crd = (char **)malloc(sizeof(char *) * (map->height + 1));
	close(fd);
	if (!map->crd)
		exit(1);
	map->crd[map->height] = 0;
}
