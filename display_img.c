/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:25:38 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/09 16:11:30 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_img_to_win(t_game *game, void *img, t_map *pos)
{
    mlx_put_image_to_window(game->mlx, game->mlx_win, img,
        pos->x * game->img->width, pos->y * game->img->height);
}


void display_img(t_game *game)
{
    char tile;
    t_map pos;

    pos.y = 0;
    while (game->map->map[pos.y])
    {
        pos.x = 0;
        while (game->map->map[pos.y][pos.x])
        {
            tile = game->map->map[pos.y][pos.x];

            if (tile == '1')
                put_img_to_win(game, game->img->img1, &pos);
            else if (tile == '0')
                put_img_to_win(game, game->img->img2, &pos);
            else if (tile == 'P')
                put_img_to_win(game, game->img->img3, &pos);
            else if (tile == 'C')
                put_img_to_win(game, game->img->img4, &pos);
            else if (tile == 'E')
                put_img_to_win(game, game->img->img5, &pos);

            pos.x++;
        }
        pos.y++;
    }
}


