/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:04:55 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/03 17:53:42 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.img = malloc(sizeof(t_img));
	if (!game.img)
		return (1);
	game.img->img1 = NULL;
	game.img->player1 = NULL;
	game.img->player2 = NULL;
	game.img->player3 = NULL;
	game.img->wall = NULL;
	game.img->pacman = NULL;
	game.img->pacman2 = NULL;

	game.mlx_win = mlx_new_window(game.mlx, 240, 180, "Baisse les yeux");
	if (!game.mlx_win)
		return (free(game.img), 1);
	display_img(game);
	mlx_key_hook(game.mlx_win, &handle_input, &game);
	if (game.img)
	{
		free(game.img);
		game.img = NULL;
	}
	mlx_loop(game.mlx);
	display_pos(game);
	return (0);
}
