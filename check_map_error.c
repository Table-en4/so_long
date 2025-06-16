/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:27:57 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/16 22:13:27 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_line_full_of_ones(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_first_and_last_lines(char **map, int height)
{
	if (!map || height < 1)
		return (0);
	if (!is_line_full_of_ones(map[0]))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!is_line_full_of_ones(map[height - 1]))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	check_first_and_last_columns(char **map, int height)
{
	int	i;
	int	len;

	if (!map || height < 1 || !map[0])
		return (0);
	i = 0;
	len = ft_strlen(map[0]);
	if (len < 1)
		return (0);
	while (i < height)
	{
		if (!map[i] || t_strlen(map[i]) != len)
			return (ft_putstr_fd("Error\n", 2), 0);
		if (map[i][0] != '1')
			return (ft_putstr_fd("Error\n", 2), 0);
		if (map[i][len - 1] != '1')
			return (ft_putstr_fd("Error\n", 2), 0);
		i++;
	}
	return (1);
}

int	is_map_surrounded_by_walls(char **map)
{
	int	height;

	if (!map)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	height = 0;
	while (map[height])
		height++;
	if (height < 3)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!check_first_and_last_lines(map, height))
		return (0);
	if (!check_first_and_last_columns(map, height))
		return (0);
	return (1);
}
