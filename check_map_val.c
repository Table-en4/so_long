/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:24:07 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/16 22:07:56 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char_in_map(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	one_player(t_map *map)
{
	int	player_count;
	int	exit_count;

	if (!map || !map->map)
		return (0);
	player_count = count_char_in_map(map->map, 'P');
	exit_count = count_char_in_map(map->map, 'E');
	if (player_count != 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (exit_count != 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	check_rec(t_map *map)
{
	int	i;
	int	first_line_len;
	int	current_line_len;

	if (!map || !map->map || !map->map[0])
		return (0);
	first_line_len = ft_strlen(map->map[0]);
	if (first_line_len == 0)
		return (0);
	i = 1;
	while (map->map[i])
	{
		current_line_len = ft_strlen(map->map[i]);
		if (current_line_len != first_line_len)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_elements(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->map)
		return (0);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1'
				&& map->map[i][j] != 'P' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'N')
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	min_map(t_map *map)
{
	if (!map || !map->map)
		return (0);
	if (map->y < 3)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (map->x < 3)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
