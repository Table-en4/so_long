/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:05:47 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/30 19:29:08 by molapoug         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_img
{
	void	*img1;
	char	*player1;
	char	*player2;
	char	*player3;
	char	*wall;
	char	*pacman;
	char	*pacman2;
}		t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
}		t_game;

int	t_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdu(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	display_img(t_game game);

#endif
