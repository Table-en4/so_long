/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:25:38 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/04 12:31:28 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_to_win(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img,
		x * game->img->width, y * game->img->height);
}

void	display_img(t_game *game)
{
	int	y;
	int	x;
	char	tile;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			tile = game->map->map[y][x];
			if (tile == '1')
				put_img_to_win(game, game->img->img1, x, y);
			else if (tile == '0')
				put_img_to_win(game, game->img->img2, x, y);
			else if (tile == 'P')
				put_img_to_win(game, game->img->img3, x, y);
			else if (tile == 'C')
				put_img_to_win(game, game->img->img4, x, y);
			else if (tile == 'E')
				put_img_to_win(game, game->img->img5, x, y);
			x++;
		}
		y++;
	}
}

