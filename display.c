/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:33:42 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/11 20:40:09 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_img(t_game *game)
{
	int	width = 30;
	int	height = 30;

	game->img->width = 30;
	game->img->height = 30;
	game->img->player1 = "assets/midiagne.xpm";
	game->img->player2 = "assets/bg.xpm";
	game->img->wall = "assets/wall.xpm";
	game->img->collectibles = "assets/col.xpm";
	game->img->fire = "assets/door.xpm";
	game->img->player3 = "assets/doaamabr.xpm";

	game->img->img1 = mlx_xpm_file_to_image(game->mlx, game->img->player1,
			&width, &height);
	game->img->img2 = mlx_xpm_file_to_image(game->mlx, game->img->player2,
			&width, &height);
	game->img->img3 = mlx_xpm_file_to_image(game->mlx, game->img->wall,
			&width, &height);
	game->img->img4 = mlx_xpm_file_to_image(game->mlx, game->img->collectibles,
			&width, &height);
	game->img->img5 = mlx_xpm_file_to_image(game->mlx, game->img->fire,
			&width, &height);
	game->img->img6 = mlx_xpm_file_to_image(game->mlx, game->img->player3,
			&width, &height);

	if (!game->img->img1 || !game->img->img2 || !game->img->img3 ||
		!game->img->img4 || !game->img->img5 || !game->img->img6)
		printf("Erreur: Impossible de charger une ou plusieurs images\n");
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
}

/*void	display_img(t_game game)
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
}*/
