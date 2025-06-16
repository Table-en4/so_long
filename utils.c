#include "so_long.h"

int	init_img(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return (cleanup_and_exit(game, 1));
	init_img_struct(game->img);
	return (0);
}

int	init_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (cleanup_and_exit(game, 1));
	return (0);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	return (0);
}

int	check_args_and_init(int ac, t_game *game)
{
	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	init_game_struct(game);
	if (init_mlx(game))
		return (1);
	if (init_img(game))
		return (1);
	if (init_map(game))
		return (1);
	return (0);
}