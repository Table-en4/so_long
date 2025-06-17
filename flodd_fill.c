/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flodd_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:14:05 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/17 14:07:36 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (!map || !map[y] || x < 0 || y < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'N')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->y + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->y)
	{
		copy[i] = ft_strdu(map->map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy[i] = NULL, copy);
}

void	free_copy(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

int	is_valid(t_game *game)
{
	char	**copy;
	int		x;
	int		y;
	int		i;
	int		j;

	if (!find_player(game, &x, &y))
		return (0);
	copy = copy_map(game->map);
	if (!copy)
		return (0);
	flood_fill(copy, x, y);
	i = 0;
	while (i < game->map->y)
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (free_copy(copy, game->map->y), 0);
			j++;
		}
		i++;
	}
	return (free_copy(copy, game->map->y), 1);
}

int	count_elements(t_game *game)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	flood_fill(game->map->map, game->map->x, game->map->y);
	while (i < game->map->y)
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'C')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}
