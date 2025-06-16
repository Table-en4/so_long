/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:46:50 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/16 20:12:50 by molapoug         ###   ########.fr       */
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
	mlx_string_put(game->mlx, game->mlx_win, 10, 20, 0xFFFF, move_str);
	ft_putstr(move_str);
	ft_putstr("\n");
	free(move_count);
	free(move_str);
}

int	handle_exit_move(t_game *g)
{
	if (is_door_valid(g) == 1)
	{
		ft_putstr("you win !!!\n");
		free_all(g);
		exit(0);
	}
	else
	{
		ft_putstr("get all collectibles before exit\n");
		g->player_exit = 1;
		return (1);
	}
}

int	check_args_and_init(int ac, t_game *game)
{
	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	init_game_struct(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return (cleanup_and_exit(game, 1));
	init_img_struct(game->img);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (cleanup_and_exit(game, 1));
	return (0);
}

int	check_map_validity(t_game *game, char *file)
{
	if (load_map(game->map, file) != 0)
		return (cleanup_and_exit(game, 1));
	if (!find_exit(game))
		return (cleanup_and_exit(game, 1));
	if (!validate_map(game))
		return (cleanup_and_exit(game, 1));
	if (!is_map_surrounded_by_walls(game->map->map))
	{
		ft_putstr_fd("Error\n", 2);
		free_all(game);
		exit(1);
	}
	return (0);
}
