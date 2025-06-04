/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:04:55 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/04 13:27:47 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:04:55 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/04 11:58:24 by molapoug         ###   ########.fr       */
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
	game.img->img2 = NULL;
	game.img->img3 = NULL;
	game.img->img4 = NULL;
	game.img->img5 = NULL;
	game.img->player1 = NULL;
	game.img->player2 = NULL;
	game.img->player3 = NULL;
	game.img->wall = NULL;
	game.img->pacman = NULL;
	game.img->pacman2 = NULL;
	game.img->fire = NULL;

	game.map = malloc(sizeof(t_map));
	if (!game.map)
		return (1);

	if (load_map(game.map, "maps/map.ber") != 0)
		return (1);

	game.mlx_win = mlx_new_window(game.mlx, 400, 160, "Plisse les yeux");
	if (!game.mlx_win)
		return (free(game.img), 1);

	assets_img(&game);
	display_img(&game);
	mlx_key_hook(game.mlx_win, &handle_input, &game);
	destroy_img(&game);
	mlx_loop(game.mlx);
	return (0);
}
