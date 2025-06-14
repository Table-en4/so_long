/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:37:33 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 17:05:23 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_door_valid(t_game *game)
{
	if (!game)
		return (0);
	if (count_elements(game) == 0)
		return (1);
	return (0);
}

int	find_exit(t_game *game)
{
	int	i;
	int	j;

	if (!game || !game->map || !game->map->map)
		return (0);
	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
