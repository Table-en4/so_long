/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:50:08 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 17:33:23 by molapoug         ###   ########.fr       */
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

int	update_player_position(t_game *g, int old_x, int old_y, int new_x, int new_y)
{
	if (g->player_exit)
	{
		g->map->map[old_y][old_x] = 'E';
		g->player_exit = 0;
	}
	else
		g->map->map[old_y][old_x] = '0';

	if (g->map->map[new_y][new_x] == 'E')
		return (handle_exit_move(g));
	else
		g->map->map[new_y][new_x] = 'P';
	return (0);
}

int	move_player(t_game *g, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	if (!g || !g->map || !g->map->map)
		return (0);
	if (!find_player(g, &old_x, &old_y))
		return (0);
	if (new_x < 0 || new_y < 0 || new_x >= g->map->x || new_y >= g->map->y)
		return (0);
	if (!g->map->map[new_y] || !g->map->map[new_y][new_x])
		return (0);
	if (g->map->map[new_y][new_x] == '1')
		return (0);
	if (g->map->map[new_y][new_x] == 'N')
	{
		printf("You loose !!!\nYou got eated !!!\n");
		free_all(g);
		exit(0);
	}
	update_player_position(g, old_x, old_y, new_x, new_y);
	mlx_clear_window(g->mlx, g->mlx_win);
	display_img(g);
	return (1);
}

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
