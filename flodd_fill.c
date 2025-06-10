/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flodd_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:14:05 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/10 20:30:44 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, t_map *map, int new_col, int old_col)
{
	if (!game)
		return ;
	if ((game->map->x || map->y) == new_col)
	{
		//coder la fonction de flood
		/*          ici           */
		flood_fill(game->map->x + 1, map->y, new_col, old_col);
		flood_fill(game->map->x - 1, map->y, new_col, old_col);
		flood_fill(game->map->x, map->y + 1, new_col, old_col);
		flodd_fill(game->map->x, map->y - 1, new_col, old_col);
	}	
}
