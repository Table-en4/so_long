/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:27:57 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 16:44:31 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_horizontal_borders(char **map, int height)
{
	int	x;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (map[height - 1][x])
	{
		if (map[height - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_vertical_borders(char **map, int height, int width)
{
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1')
			return (1);
		if (map[y][width - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	fl_line(t_game *game)
{
	char	**map;
	int		height;
	int		width;

	if (!game || !game->map || !game->map->map)
		return (1);
	map = game->map->map;
	height = game->map->y;
	width = game->map->x;
	if (check_horizontal_borders(map, height) != 0)
		return (1);
	if (check_vertical_borders(map, height, width) != 0)
		return (1);
	return (0);
}

void	calc_map_dimensions(t_map *map)
{
	int	i;

	map->y = 0;
	while (map->map[map->y])
		map->y++;
	map->x = 0;
	if (map->y > 0)
	{
		i = 0;
		while (map->map[0][i])
		{
			map->x++;
			i++;
		}
	}
}
