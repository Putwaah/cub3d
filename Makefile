# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 14:37:24 by jtoulous          #+#    #+#              #
#    Updated: 2022/12/21 14:42:23 by jtoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
CC		= @clang
CFLAGS	=  -I/usr/include -Imlx_linux -O3 -g
RM		= @rm -f
CLEAR	= @clear

# FILE
SRC	= ./check_map.c ./check_params.c ./handle.c ./init.c ./main.c ./ray_K_string.c ./utils.c  
OBJ	= $(SRC:.c=.o)

#LIBFT
LIBFT_PATH = libft/ --no-print-directory
LIBFT_NAME = libft/libft.a

# MINILIBX
MLX_PATH		= ./minilibx-linux --no-print-directory

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_NAME):
	@make -C $(MLX_PATH)

$(NAME): $(OBJ)
	@make -C $(MLX_PATH)
	@make -C $(LIBFT_PATH)
	$(CC) $(OBJ) $(LIBFT_NAME) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean: 
	@make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ)
	
fclean: clean
	@make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)
	
re: fclean all

.PHONY:
	re all clean fclean
