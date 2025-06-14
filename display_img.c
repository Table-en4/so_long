/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:25:38 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 17:27:50 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_to_win(t_game *game, void *img, t_map *pos)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img,
		pos->x * game->img->width, pos->y * game->img->height);
}

void	display_tile(t_game *game, char tile, t_map *pos)
{
	if (tile == '1')
		put_img_to_win(game, game->img->img3, pos);
	else if (tile == '0')
		put_img_to_win(game, game->img->img2, pos);
	else if (tile == 'P')
		put_img_to_win(game, game->img->img1, pos);
	else if (tile == 'C')
		put_img_to_win(game, game->img->img4, pos);
	else if (tile == 'E')
	{
		put_img_to_win(game, game->img->img5, pos);
		if (game->player_exit && pos->x == game->exit_x
			&& pos->y == game->exit_y)
			put_img_to_win(game, game->img->img1, pos);
	}
	else if (tile == 'N')
		put_img_to_win(game, game->img->img6, pos);
}

void	display_img(t_game *game)
{
	char	tile;
	t_map	pos;

	pos.y = 0;
	while (game->map->map[pos.y])
	{
		pos.x = 0;
		while (game->map->map[pos.y][pos.x])
		{
			tile = game->map->map[pos.y][pos.x];
			display_tile(game, tile, &pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	exit_game(t_game *game)
{
	int	player_x;
	int	player_y;

	if (find_player(game, &player_x, &player_y))
	{
		if (game->map->map[player_y][player_x] == 'E')
		{
			free_all(game);
			exit(0);
		}
	}
}
