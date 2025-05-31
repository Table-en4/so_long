/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:05:47 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/31 16:08:42 by molapoug         ###   ########.fr       */
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
	char	*player1;
	char	*player2;
	char	*player3;
	char	*wall;
	char	*pacman;
	char	*pacman2;
	char	*bg;
	int		height;
	int		width;
}		t_img;

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
}		t_game;

int	t_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdu(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	display_img(t_game game);
int	handle_input(int keysym, t_game *game);

#endif
