/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:05:47 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/14 17:54:58 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_img
{
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	char	*player1;
	char	*player2;
	char	*player3;
	char	*wall;
	char	*pacman;
	char	*pacman2;
	char	*fire;
	char	*bg;
	char	*collectibles;
	int		height;
	int		width;
}		t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	*sign;
	char	**map;
	int	y;
	int	x;
	int	c;
	int	p;
	int	e;
}		t_map;

typedef struct	s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_img	*img;
	int	player_exit;
	int	exit_x;
	int	exit_y;
}		t_game;

int	t_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdu(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	display_img(t_game *game);
int	handle_input(int keysym, t_game *game);
void	display_pos(t_game game);
void	assets_img(t_game *game);
int	load_map(t_map *map, char *file);
void	destroy_img(t_game *game);
void	free_map(t_map *map);
void	put_img_to_win(t_game *game, void *img, t_map *pos);
int	free_all(t_game *game);
void	exit_game(t_game *game);
int	find_player(t_game *game, int *x, int *y);
int	is_valid(t_game *game);
void	flood_fill(char **map, int x, int y);
int	count_elements(t_game *game);
int	is_door_valid(t_game *game);
int	find_exit(t_game *game);
int	fl_line(t_game *game);
void	calc_map_dimensions(t_map *map);
void	display_move_counter(t_game *game, int moves);
int	handle_exit_move(t_game *g);

#endif
