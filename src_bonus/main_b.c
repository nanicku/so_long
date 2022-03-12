/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:35:21 by mshad             #+#    #+#             */
/*   Updated: 2021/12/09 21:09:09 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		error_exit("Too few arguments\n");
	else if (argc > 2)
		error_exit("Too many arguments\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error_exit("Can't find file\n");
		close(fd);
	}
}

static void	init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.col * 75,
			game->map.row * 75, "so_long");
	draw_map(&game->imgs, game, &game->map);
	game->moves = 0;
	game->coconut = 0;
	position_player(game);
	count_collectibles(game);
	game->num = ft_strdup("");
	mlx_string_put(game->mlx, game->win, 20, 20, 0x000000, "0");
}

static int	close_game(void)
{
	ft_putstr_fd("\033[91mYou closed the game\n", 1);
	exit(0);
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		ft_putstr_fd("\033[91mYou closed the game\n", 1);
		exit(0);
	}
	if (keycode == 0)
		moveleft(game);
	if (keycode == 1)
		movedown(game);
	if (keycode == 2)
		moveright(game);
	if (keycode == 13)
		moveup(game);
	mlx_put_image_to_window(game->mlx,
		game->win, game->imgs.wall.img, 0, 0);
	game->tmp = game->num;
	game->num = ft_itoa(game->moves);
	free((*game).tmp);
	mlx_string_put(game->mlx, game->win, 20, 20, 0x000000, game->num);
	position_coconut(game);
	move_coconut(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_file(argc, argv);
	parser_map(argv[1], &game.map);
	init(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, 0);
	mlx_loop(game.mlx);
}
