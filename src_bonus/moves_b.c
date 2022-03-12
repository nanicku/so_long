/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:39:01 by mshad             #+#    #+#             */
/*   Updated: 2021/12/09 13:10:31 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	qwe(t_game *game)
{
	game->map.map[game->posy][game->posx] = '0';
	game->moves++;
}

void	moveup(t_game *game)
{
	if (game->map.map[game->posy - 1][game->posx] != '1')
	{
		if (game->map.map[game->posy - 1][game->posx] == 'C')
		{
			game->map.map[game->posy - 1][game->posx] = '0';
			count_collectibles(game);
		}
		if (game->map.map[game->posy - 1][game->posx] == 'E'
			&& game->coins == 0)
			win_exit();
		if (game->map.map[game->posy - 1][game->posx] == 'R')
			die_exit();
		else if (game->map.map[game->posy - 1][game->posx] != 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, game->posx * 75, game->posy * 75);
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, game->posx * 75, (game->posy - 1) * 75);
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.player.img, game->posx * 75, (game->posy - 1) * 75);
			game->map.map[game->posy - 1][game->posx] = 'P';
			qwe(game);
			game->posy--;
		}
	}
}

void	movedown(t_game *game)
{
	if (game->map.map[game->posy + 1][game->posx] != '1')
	{
		if (game->map.map[game->posy + 1][game->posx] == 'C')
		{
			game->map.map[game->posy + 1][game->posx] = '0';
			count_collectibles(game);
		}
		if (game->map.map[game->posy + 1][game->posx] == 'E'
			&& game->coins == 0)
			win_exit();
		if (game->map.map[game->posy + 1][game->posx] == 'R')
			die_exit();
		else if (game->map.map[game->posy + 1][game->posx] != 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, game->posx * 75, game->posy * 75);
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, game->posx * 75, (game->posy + 1) * 75);
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.player.img, game->posx * 75, (game->posy + 1) * 75);
			game->map.map[game->posy + 1][game->posx] = 'P';
			qwe(game);
			game->posy++;
		}
	}
}

void	moveleft(t_game *game)
{
	if (game->map.map[game->posy][game->posx - 1] != '1')
	{
		if (game->map.map[game->posy][game->posx - 1] == 'C')
		{
			game->map.map[game->posy][game->posx - 1] = '0';
			count_collectibles(game);
		}
		if (game->map.map[game->posy][game->posx - 1] == 'E'
			&& game->coins == 0)
			win_exit();
		if (game->map.map[game->posy][game->posx - 1] == 'R')
			die_exit();
		else if (game->map.map[game->posy][game->posx - 1] != 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, game->posx * 75, game->posy * 75);
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, (game->posx - 1) * 75, game->posy * 75);
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.player.img, (game->posx - 1) * 75, game->posy * 75);
			game->map.map[game->posy][game->posx - 1] = 'P';
			qwe(game);
			game->posx--;
		}
	}
}

void	moveright(t_game *game)
{
	if (game->map.map[game->posy][game->posx + 1] != '1')
	{
		if (game->map.map[game->posy][game->posx + 1] == 'C')
		{
			game->map.map[game->posy][game->posx + 1] = '0';
			count_collectibles(game);
		}
		if (game->map.map[game->posy][game->posx + 1] == 'E'
			&& game->coins == 0)
			win_exit();
		if (game->map.map[game->posy][game->posx + 1] == 'R')
			die_exit();
		else if (game->map.map[game->posy][game->posx + 1] != 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, game->posx * 75, game->posy * 75);
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, (game->posx + 1) * 75, game->posy * 75);
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.player.img, (game->posx + 1) * 75, game->posy * 75);
			game->map.map[game->posy][game->posx + 1] = 'P';
			qwe(game);
			game->posx++;
		}
	}
}
