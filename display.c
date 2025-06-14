/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:33:42 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 17:26:27 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_check(t_game *game)
{
	if (!game->img->img1 || !game->img->img2 || !game->img->img3
		||!game->img->img4 || !game->img->img5 || !game->img->img6)
		printf("Error\n");
}

void	assets_img(t_game *g)
{
	int	w;
	int	h;

	h = 30;
	w = 30;
	g->img->width = 30;
	g->img->height = 30;
	g->img->player1 = "assets/player1.xpm";
	g->img->player2 = "assets/bg.xpm";
	g->img->wall = "assets/wall.xpm";
	g->img->collectibles = "assets/col.xpm";
	g->img->fire = "assets/door.xpm";
	g->img->player3 = "assets/pacman2.xpm";
	g->img->img1 = mlx_xpm_file_to_image(g->mlx, g->img->player1, &w, &h);
	g->img->img2 = mlx_xpm_file_to_image(g->mlx, g->img->player2, &w, &h);
	g->img->img3 = mlx_xpm_file_to_image(g->mlx, g->img->wall, &w, &h);
	g->img->img4 = mlx_xpm_file_to_image(g->mlx, g->img->collectibles, &w, &h);
	g->img->img5 = mlx_xpm_file_to_image(g->mlx, g->img->fire, &w, &h);
	g->img->img6 = mlx_xpm_file_to_image(g->mlx, g->img->player3, &w, &h);
	err_check(g);
}

void	destroy_img(t_game *game)
{
	if (game->img->img1)
		mlx_destroy_image(game->mlx, game->img->img1);
	if (game->img->img2)
		mlx_destroy_image(game->mlx, game->img->img2);
	if (game->img->img3)
		mlx_destroy_image(game->mlx, game->img->img3);
	if (game->img->img4)
		mlx_destroy_image(game->mlx, game->img->img4);
	if (game->img->img5)
		mlx_destroy_image(game->mlx, game->img->img5);
	if (game->img->img6)
		mlx_destroy_image(game->mlx, game->img->img6);
}
