/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:41:29 by mshad             #+#    #+#             */
/*   Updated: 2021/12/08 21:41:30 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->posx = j;
				game->posy = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	count_collectibles(t_game *game)
{
	int	i;
	int	j;

	game->coins = 0;
	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.map[i][j] == 'C')
				game->coins++;
			j++;
		}
		i++;
	}
}
