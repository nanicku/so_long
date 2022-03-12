/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:41:22 by mshad             #+#    #+#             */
/*   Updated: 2021/12/09 20:53:41 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_imgs
{
	t_img	collec;
	t_img	player;
	t_img	exit;
	t_img	space;
	t_img	wall;
	t_img	cocon1;
	t_img	cocon2;
}	t_imgs;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_imgs	imgs;
	char	*num;
	char	*tmp;
	int		moves;
	int		posx;
	int		posy;
	int		posx_r;
	int		posy_r;
	int		coins;
	int		coconut;
}	t_game;

void	check_map(t_map *map);
void	parser_map(char *filename, t_map *map);
void	draw_map(t_imgs *imgs, t_game *game, t_map *map);
void	moveup(t_game *game);
void	movedown(t_game *game);
void	moveleft(t_game *game);
void	moveright(t_game *game);
void	position_player(t_game *game);
void	count_collectibles(t_game *game);
void	error_exit(char *message);
void	win_exit(void);
void	die_exit(void);
void	position_coconut(t_game *game);
void	move_coconut(t_game *game);

#endif