/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:50:08 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/03 11:53:39 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->img);
	exit(0);
	return (1);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		free_all(game);
	}
	else if (keysym == XK_W)
	{
		return (0);
	}
	//move du player vers le haut donc potentiellement y + 10
	return (0);
}
