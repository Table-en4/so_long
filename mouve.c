/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:50:08 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/11 20:18:11 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(t_game *game, int *x, int *y)
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
			if (game->map->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
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
	if (g->map->map[new_y][new_x] == 'E')
	{
		printf("you win !!!\n");
		free_all(g);
		exit(0);
	}
	g->map->map[old_y][old_x] = '0';
	g->map->map[new_y][new_x] = 'P';
	mlx_clear_window(g->mlx, g->mlx_win);
	return (display_img(g), 0);
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

int	handle_input(int keysym, t_game *game)
{
	int	x;
	int	y;
	static int	i;

	if (game)
	{
		if (!find_player(game, &x, &y))
			return (1);
		if (keysym == XK_Escape)
			free_all(game);
		else if (keysym == XK_W || keysym == XK_w || keysym == 65362)
			i += move_player(game, x, y - 1);
		else if (keysym == XK_S || keysym == XK_s || keysym == 65364)
			i += move_player(game, x, y + 1);
		else if (keysym == XK_A || keysym == XK_a || keysym == 65361)
			i += move_player(game, x - 1, y);
		else if (keysym == XK_D || keysym == XK_d || keysym == 65363)
			i += move_player(game, x + 1, y);
		printf("%d\n", i++);
	}
	return (1);
}
