# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molapoug <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 10:15:52 by molapoug          #+#    #+#              #
#    Updated: 2025/06/11 19:12:24 by molapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror -Imlx

MLXFLAGS = -Lmlx -lmlx_Linux -lXext -lX11 -lXrandr -lXcursor -lXrender -lXfixes -lXinerama -lXcomposite -lXdamage -lXxf86vm -lXau -lXdmcp

LIBFT = libft/
FT_PRINTF = ft_printf/
MLX = mlx/

AR = ar rcs
RM = rm -f

SRC = so_long.c display.c get_next_line.c \
      get_next_line_utils.c mouve.c read_map.c \
      display_img.c flodd_fill.c 

OBJ = $(SRC:.c=.o)

LIBS = $(LIBFT)libft.a $(FT_PRINTF)libftprintf.a $(MLX)libmlx_Linux.a

# Color
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@echo "$(YELLOW)😎🤙Linking executable$(PURPLE) $(NAME)$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf $(MLXFLAGS) -o $(NAME)

%.o: %.c so_long.h
	@echo "$(CYAN)🔥Compiling$(GREEN) $<$(NC)"
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(FT_PRINTF) -c $< -o $@

$(LIBFT)libft.a:
	@make -C $(LIBFT)

$(FT_PRINTF)libftprintf.a:
	@make -C $(FT_PRINTF)

clean:
	@echo "$(CYAN)🧹Cleaning object files$(NC)"
	@$(RM) $(OBJ)
	@make -C $(LIBFT) clean
	@make -C $(FT_PRINTF) clean

fclean: clean
	@echo "$(CYAN)🚮Cleaning$(RED) $(NAME)$(NC)"
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(FT_PRINTF) fclean

re: fclean all

bonus:
	@echo "$(PURPLE)💡Bonus not implemented yet$(NC)"

.PHONY: all clean fclean re bonus

