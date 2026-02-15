# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 17:05:10 by asauvage          #+#    #+#              #
#    Updated: 2026/02/15 15:36:33 by asauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.c \
	  malloc_map.c \
	  free_tab.c \
	  utils.c \
	  utils_moves.c \
	  verif_map.c \
	  init_win.c \
	  display_map.c \
	  my_mlx_hook.c \
	  moves.c \
	  clear_all.c \
	  patrol_move.c \
	  start_patrols.c

NAME = so_long

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)

MLX_PATH = ./minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_INC = $(MLX_PATH)

INC = so_long.h

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(MLX_LIB):
	make -C $(MLX_PATH)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -L$(MLX_PATH) -lXext -lX11 -lm -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
