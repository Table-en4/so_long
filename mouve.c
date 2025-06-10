/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:50:08 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/10 12:42:34 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:50:08 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/09 16:17:35 by molapoug         ###   ########.fr       */
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

void	move_player(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	if (!game || !game->map || !game->map->map)
		return ;
	if (!find_player(game, &old_x, &old_y))
		return ;
	if (new_x < 0 || new_y < 0 || new_x >= game->map->x || new_y >= game->map->y)
		return ;
	if (!game->map->map[new_y] || !game->map->map[new_y][new_x])
		return ;
	if (game->map->map[new_y][new_x] == '1')
		return ;
	if (game->map->map[new_y][new_x] == 'E')
	{
		printf("you win !!!\n");
		free_all(game);
		exit(0);
	}
	game->map->map[old_y][old_x] = '0';
	game->map->map[new_y][new_x] = 'P';
	mlx_clear_window(game->mlx, game->mlx_win);
	display_img(game);
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
	int	i;

	i = 0;
	if (!game)
		return (0);
	if (!find_player(game, &x, &y))
		return (0);
	if (keysym == XK_Escape)
		free_all(game);
	else if (keysym == XK_W || keysym == XK_w || keysym == 65362)
		move_player(game, x, y - 1);
	else if (keysym == XK_S || keysym == XK_s || keysym == 65364)
		move_player(game, x, y + 1);
	else if (keysym == XK_A || keysym == XK_a || keysym == 65361)
		move_player(game, x - 1, y);
	else if (keysym == XK_D || keysym == XK_d || keysym == 65363)
		move_player(game, x + 1, y);
	return (0);
}
