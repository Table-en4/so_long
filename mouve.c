/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:50:08 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/04 19:11:25 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	free(game->map);
	free(game->img);
	exit(0);
	return (1);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		free_all(game);
	}
	else if (keysym == XK_W && keysym == XK_w)
	{
		return (0);
	}

	return (0);
}
