/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:46:50 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 17:50:43 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_game *game)
{
	if (!game)
		return (1);
	if (game->img)
	{
		destroy_img(game);
		free(game->img);
	}
	if (game->map)
	{
		free_map(game->map);
		free(game->map);
	}
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (1);
}

void	display_move_counter(t_game *game, int moves)
{
	char	*move_count;
	char	*move_str;

	if (!game || !game->mlx || !game->mlx_win)
		return ;
	move_count = ft_itoa(moves);
	if (!move_count)
		return ;
	move_str = ft_strjoin("Moves: ", move_count);
	if (!move_str)
	{
		free(move_count);
		return ;
	}
	mlx_string_put(game->mlx, game->mlx_win, 10, 20, 0x000000, move_str);
	printf("%s\n", move_str);
	free(move_count);
	free(move_str);
}

int	handle_exit_move(t_game *g)
{
	if (is_door_valid(g) == 1)
	{
		printf("you win !!!\n");
		free_all(g);
		exit(0);
	}
	else
	{
		printf("get all collectibles before exit\n");
		g->player_exit = 1;
		return (1);
	}
}
