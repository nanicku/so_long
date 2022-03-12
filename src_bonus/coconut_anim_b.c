/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coconut_anim_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:08:34 by mshad             #+#    #+#             */
/*   Updated: 2021/12/09 21:10:14 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_coconut(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.map[i][j] == 'R')
			{
				game->posx_r = j;
				game->posy_r = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	move_coconut1(t_game *game)
{
	if (game->map.map[game->posy_r - 1][game->posx_r] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.space.img, game->posx_r * 75, game->posy_r * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.space.img, game->posx_r * 75, (game->posy_r - 1) * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.cocon2.img, game->posx_r * 75, (game->posy_r - 1) * 75);
			game->map.map[game->posy_r - 1][game->posx_r] = 'R';
			game->map.map[game->posy_r][game->posx_r] = '0';
	}
	else if (game->map.map[game->posy_r + 1][game->posx_r] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.space.img, game->posx_r * 75, game->posy_r * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.space.img, game->posx_r * 75, (game->posy_r + 1) * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.cocon1.img, game->posx_r * 75, (game->posy_r + 1) * 75);
			game->map.map[game->posy_r + 1][game->posx_r] = 'R';
			game->map.map[game->posy_r][game->posx_r] = '0';
	}
	else
		game->coconut = 1;
	return ;
}

static void	move_coconut2(t_game *game)
{
	if (game->map.map[game->posy_r][game->posx_r - 1] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.space.img, game->posx_r * 75, game->posy_r * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.space.img, (game->posx_r - 1) * 75, game->posy_r * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.cocon2.img, (game->posx_r - 1) * 75, game->posy_r * 75);
			game->map.map[game->posy_r][game->posx_r - 1] = 'R';
			game->map.map[game->posy_r][game->posx_r] = '0';
	}
	else if (game->map.map[game->posy_r][game->posx_r + 1] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.space.img, game->posx_r * 75, game->posy_r * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.space.img, (game->posx_r + 1) * 75, game->posy_r * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.cocon1.img, (game->posx_r + 1) * 75, game->posy_r * 75);
			game->map.map[game->posy_r][game->posx_r + 1] = 'R';
			game->map.map[game->posy_r][game->posx_r] = '0';
	}
	else
		game->coconut = 0;
	return ;
}

void	move_coconut(t_game *game)
{
	if (game->coconut == 0)
		move_coconut1(game);
	if (game->coconut == 1)
		move_coconut2(game);
}
