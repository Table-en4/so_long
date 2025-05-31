/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:33:42 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/31 17:13:11 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_img(t_game game)
{
	int	width;
	int	height;

	width = 30;
	height = 30;
	if (!game.img)
		return ;
	game.img->player1 = "assets/player1.xpm";
	game.img->player2 = "assets/player2.xpm";
	game.img->img1 = mlx_xpm_file_to_image(game.mlx, game.img->player1,
			&width, &height);
	if (!game.img->img1)
	{
		printf("erreur impossible d'afficher l'image %s\n", game.img->player1);
		return ;
	}
	//game.img->img2 = mlx_xpm_file_to_image(game.mlx, game.img->player2,
			//&width, &height);
	//mlx_put_image_to_window(game.mlx, game.mlx_win, game.img->img2, 50, 50);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img->img1, 0, 0);
}
