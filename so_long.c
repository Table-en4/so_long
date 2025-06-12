/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:04:55 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/12 17:32:53 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->img = NULL;
	game->map = NULL;
}

void	init_img_struct(t_img *img)
{
	img->img1 = NULL;
	img->img2 = NULL;
	img->img3 = NULL;
	img->img4 = NULL;
	img->img5 = NULL;
	img->player1 = NULL;
	img->player2 = NULL;
	img->player3 = NULL;
	img->wall = NULL;
	img->pacman = NULL;
	img->pacman2 = NULL;
	img->fire = NULL;
	img->width = 30;
	img->height = 30;
}

int	cleanup_and_exit(t_game *game, int exit_code)
{
	if (game->img)
	{
		destroy_img(game);
		free(game->img);
	}
	if (game->map)
	{
		free_map(game->map);
		free(game->map);
	}
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (exit_code);
}

int	validate_map(t_game *game)
{
	if (!is_valid(game))
	{
		printf("Error\nbad map: ");
		printf("there is not C or E\n");
		printf("or bad map path to C or E\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	t_game	game;

	init_game_struct(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.img = malloc(sizeof(t_img));
	if (!game.img)
		return (cleanup_and_exit(&game, 1));
	init_img_struct(game.img);
	game.map = malloc(sizeof(t_map));
	if (!game.map)
		return (cleanup_and_exit(&game, 1));
	if (load_map(game.map, "maps/map.ber") != 0)
		return (cleanup_and_exit(&game, 1));
	if (!validate_map(&game))
		return (cleanup_and_exit(&game, 1));
	game.mlx_win = mlx_new_window(game.mlx, game.map->x * 30, game.map->y * 30,
		"Plisse les yeux ou jtegoume");
	if (!game.mlx_win)
		return (cleanup_and_exit(&game, 1));
	assets_img(&game);
	display_img(&game);
	mlx_hook(game.mlx_win, 17, 0, &free_all, &game);
	mlx_key_hook(game.mlx_win, &handle_input, &game);
	printf("nombre de collectibles ; %d\n", count_elements(&game));
	exit_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
