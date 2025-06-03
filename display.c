/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:33:42 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/03 17:25:27 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_img(t_game game)
{
	int	width = 30;
	int	height = 30;

	game.img->player1 = "assets/player1.xpm";
	game.img->player2 = "assets/player2.xpm";
	game.img->player3 = "assets/player3.xpm";
	game.img->wall = "assets/wall.xpm";
	game.img->img1 = mlx_xpm_file_to_image(game.mlx, game.img->player1,
			&width, &height);
	game.img->img2 = mlx_xpm_file_to_image(game.mlx, game.img->player2,
			&width, &height);
	game.img->img3 = mlx_xpm_file_to_image(game.mlx, game.img->player3,
			&width, &height);
	game.img->img4 = mlx_xpm_file_to_image(game.mlx, game.img->wall,
			&width, &height);

}

void	destroy_img(t_game game)
{
	mlx_destroy_image(game.mlx, game.img->img1);
	mlx_destroy_image(game.mlx, game.img->img2);
	mlx_destroy_image(game.mlx, game.img->img3);
	mlx_destroy_image(game.mlx, game.img->img4);
}

void	display_img(t_game game)
{
	int	width;
	int	height;

	width = 30;
	height = 30;
	if (!game.img)
		return ;
	assets_img(game);
	if (!game.img)
	{
		printf("erreur impossible d'afficher l'image : %s\n", game.img->player1);
		printf("erreur impossible d'afficher l'image : %s\n", game.img->player2);
		free(game.img);
		return ;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img->img2, 50, 50);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img->img1, 200, 150);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img->img3, 100, 75);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img->img4, 0, 0);
	destroy_img(game);
}
