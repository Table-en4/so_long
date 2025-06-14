/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:50:08 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 17:55:37 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	err_p(t_game *game)
{
	if (!game || !game->map || !game->map->map)
		return (1);
	return (0);
}

int	find_player(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	err_p(game);
	if (game->player_exit)
	{
		*x = game->exit_x;
		return (*y = game->exit_y, 1);
	}
	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'P')
			{
				*x = j;
				return (*y = i, 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	update_player_position(t_game *g, t_pos old, t_pos new)
{
	if (g->player_exit)
	{
		g->map->map[old.y][old.x] = 'E';
		g->player_exit = 0;
	}
	else
		g->map->map[old.y][old.x] = '0';
	if (g->map->map[new.y][new.x] == 'E')
		return (handle_exit_move(g));
	g->map->map[new.y][new.x] = 'P';
	return (0);
}


int	move_player(t_game *g, int new_x, int new_y)
{
	t_pos	old;
	t_pos	new;

	if (!g || !g->map || !g->map->map)
		return (0);
	if (!find_player(g, &old.x, &old.y))
		return (0);
	if (new_x < 0 || new_y < 0
		|| new_x >= g->map->x || new_y >= g->map->y)
		return (0);
	if (!g->map->map[new_y] || !g->map->map[new_y][new_x])
		return (0);
	if (g->map->map[new_y][new_x] == '1')
		return (0);
	if (g->map->map[new_y][new_x] == 'N')
	{
		printf("You lose !!!\nYou got eaten !!!\n");
		free_all(g);
		exit(0);
	}
	new.x = new_x;
	new.y = new_y;
	update_player_position(g, old, new);
	mlx_clear_window(g->mlx, g->mlx_win);
	return (display_img(g), 1);
}

int	handle_input(int keysym, t_game *game)
{
	int			x;
	int			y;
	static int	moves = 0;

	if (!game)
		return (1);
	if (!find_player(game, &x, &y))
		return (1);
	if (keysym == XK_Escape)
		free_all(game);
	else if (keysym == XK_W || keysym == XK_w || keysym == 65362)
		moves += move_player(game, x, y - 1);
	else if (keysym == XK_S || keysym == XK_s || keysym == 65364)
		moves += move_player(game, x, y + 1);
	else if (keysym == XK_A || keysym == XK_a || keysym == 65361)
		moves += move_player(game, x - 1, y);
	else if (keysym == XK_D || keysym == XK_d || keysym == 65363)
		moves += move_player(game, x + 1, y);
	display_move_counter(game, moves);
	return (1);
}
