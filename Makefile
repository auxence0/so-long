# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 17:05:10 by asauvage          #+#    #+#              #
#    Updated: 2026/01/24 13:00:42 by asauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c \
	  malloc_map.c \
	  free_tab.c \
	  utils.c \
	  verif_map.c
NAME = so_long

LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)

MLX_PATH = ./minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_INC = $(MLX_PATH)

INC = fdf.h

OBJ = $(SRC:.c=.o)

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(MLX_LIB):
	make -C $(MLX_PATH)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) -L$(MLX_PATH) -lXext -lX11 -lm -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I. -I $(LIBFT_INC) -I$(MLX_INC) -c $< -o $@ -g

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re
