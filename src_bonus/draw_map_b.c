/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:34:59 by mshad             #+#    #+#             */
/*   Updated: 2021/12/09 20:06:16 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_imgs(t_imgs *imgs, t_game *game)
{
	imgs->wall.img = mlx_xpm_file_to_image(game->mlx,
			"img/wall.xpm",
			&imgs->wall.img_width, &imgs->wall.img_height);
	imgs->collec.img = mlx_xpm_file_to_image(game->mlx,
			"img/collectible.xpm",
			&imgs->collec.img_width, &imgs->collec.img_height);
	imgs->player.img = mlx_xpm_file_to_image(game->mlx,
			"img/player.xpm",
			&imgs->player.img_width, &imgs->player.img_height);
	imgs->space.img = mlx_xpm_file_to_image(game->mlx,
			"img/space.xpm",
			&imgs->space.img_width, &imgs->space.img_height);
	imgs->exit.img = mlx_xpm_file_to_image(game->mlx,
			"img/exit.xpm",
			&imgs->exit.img_width, &imgs->exit.img_height);
}

static void	init_coco(t_imgs *imgs, t_game *game)
{
	imgs->cocon1.img = mlx_xpm_file_to_image(game->mlx,
			"img/cocon1.xpm",
			&imgs->cocon1.img_width, &imgs->cocon1.img_height);
	imgs->cocon2.img = mlx_xpm_file_to_image(game->mlx,
			"img/cocon2.xpm",
			&imgs->cocon2.img_width, &imgs->cocon2.img_height);
}

static void	put_img(t_imgs *imgs, t_game *game, t_map *map, const int *num)
{
	if (map->map[num[0]][num[1]] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			imgs->space.img, num[1] * 75, num[0] * 75);
	if (map->map[num[0]][num[1]] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			imgs->space.img, num[1] * 75, num[0] * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			imgs->exit.img, num[1] * 75, num[0] * 75);
	}
	if (map->map[num[0]][num[1]] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			imgs->space.img, num[1] * 75, num[0] * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			imgs->collec.img, num[1] * 75, num[0] * 75);
	}
	if (map->map[num[0]][num[1]] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			imgs->space.img, num[1] * 75, num[0] * 75);
		mlx_put_image_to_window(game->mlx, game->win,
			imgs->player.img, num[1] * 75, num[0] * 75);
	}
}

void	draw_map(t_imgs *imgs, t_game *game, t_map *map)
{
	int	num[2];

	init_imgs(imgs, game);
	init_coco(imgs, game);
	num[0] = 0;
	while (num[0] < map->row)
	{
		num[1] = 0;
		while (num[1] < map->col)
		{
			if (map->map[num[0]][num[1]] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					imgs->wall.img, num[1] * 75, num[0] * 75);
			if (map->map[num[0]][num[1]] == 'R')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					imgs->space.img, num[1] * 75, num[0] * 75);
				mlx_put_image_to_window(game->mlx, game->win,
					imgs->cocon1.img, num[1] * 75, num[0] * 75);
			}
			put_img(imgs, game, map, num);
			num[1]++;
		}
		num[0]++;
	}
}
