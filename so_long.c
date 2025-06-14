/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:04:55 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 18:03:00 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->img = NULL;
	game->map = NULL;
	game->player_exit = 0;
	game->exit_x = -1;
	game->exit_y = -1;
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
		printf("Error\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("Error\n"), 1);
	init_game(game, av);
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
