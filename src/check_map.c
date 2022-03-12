/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:34:47 by mshad             #+#    #+#             */
/*   Updated: 2021/12/08 22:54:04 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_specification(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row - 1)
	{
		j = 0;
		while (j < map->col - 1)
		{
			if (!ft_strchr("10PEC", map->map[i][j]))
				error_exit("Not valid map\n");
			j++;
		}
		i++;
	}
}

static void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] == '1')
		i++;
	if (map->map[0][i])
		error_exit("Not valid map: no wall\n");
	if (ft_strncmp(map->map[0],
			map->map[map->row - 1], ft_strlen(map->map[0])))
		error_exit("Not valid map: no wall\n");
	i = 1;
	while (i < map->row - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->col - 1] != '1')
			error_exit("Not valid map: no wall\n");
		i++;
	}
}

static void	check_player(t_map *map)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (i < map->row - 1)
	{
		j = 0;
		while (j < map->col - 1)
		{
			if (map->map[i][j] == 'P')
				num++;
			j++;
		}
		i++;
	}
	if (num != 1)
		error_exit("Not valid map: player\n");
}

static void	check_char(t_map *map, char ch)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (i < map->row - 1)
	{
		j = 0;
		while (j < map->col - 1)
		{
			if (map->map[i][j] == ch)
				num++;
			j++;
		}
		i++;
	}
	if (num < 1)
		error_exit("Not valid map: no exit or collectibles\n");
}

void	check_map(t_map *map)
{
	check_specification(map);
	check_walls(map);
	check_player(map);
	check_char(map, 'E');
	check_char(map, 'C');
}
