/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:38:55 by mshad             #+#    #+#             */
/*   Updated: 2021/12/08 22:53:25 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_col(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	map->col = (int)ft_strlen(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		if (map->col != (int)ft_strlen(line))
			error_exit("Not valid map\n");
		free(line);
	}
	free(line);
	close(fd);
}

static void	get_row(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	map->row = 0;
	while (get_next_line(fd, &line))
	{
		map->row++;
		free(line);
	}
	free(line);
	close(fd);
}

static void	get_map(char *filename, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map->map = malloc(sizeof(char *) * (map->row + 1));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		map->map[i] = line;
		i++;
	}
	free(line);
	map->map[i] = NULL;
	close(fd);
}

void	parser_map(char *filename, t_map *map)
{
	get_col(filename, map);
	get_row(filename, map);
	get_map(filename, map);
	if (map->col < 3 || map->row < 3)
		error_exit("Not valid map\n");
	check_map(map);
}
