/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:31:59 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/23 18:12:41 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: %s", strerror(errno), file);
		exit(1);
	}
	return (fd);
}

int	verif_len_line(char *line, size_t pre_len, char **tab)
{
	if (ft_findchar(line, '\n') != -1)
		line[ft_strlen(line) - 1] = '\0';
	if (pre_len != ft_strlen(line))
	{
		free_tab(tab);
		ft_putstr_fd("the size of the map is wrong\n", 2);
		exit (1);
	}
	return (ft_strlen(line));
}

void	malloc_lines(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open_file(file);
	i = -1;
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	while (++i < map->height - 1)
	{
		if (!line)
			break ;
		if (ft_findchar(line, '\n') != -1)
			line[ft_strlen(line) - 1] = '\0';
		map->crd[i] = ft_strdup(line);
		if (!map->crd[i])
			free_tab(map->crd);
		free(line);
		line = get_next_line(fd);
		map->width = verif_len_line(line, map->width, map->crd);
	}
	close(fd);
}

void	malloc_height(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open_file(file);
	map->height = 0;
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			break ;
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	if (!map->height)
	{
		ft_putstr_fd("There is no line in the map\n", 2);
		close(fd);
		exit(1);
	}
	map->crd = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->crd)
		exit(1);
	close(fd);
	map->crd[map->height] = 0;
}
