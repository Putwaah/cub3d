NAME = cub3d

SRC = main.c\
	  init.c\
	  check.c\
	  utils.c\

CFLAGS = -Wall -Wextra -Werror -I/usr/include -IMLX42 

OBJ = $(SRC:.c=.o)

%.o: %.c
	@clang $(CFLAGS) -I/usr/include -IMLX42 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s
	@make $(OBJ) libft/libft.a MLX42/libmlx42.a -LMLX42 -lXext -l42 -lm -lz -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C libft -s
	@make clean -C MLX42 -s

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft -s

re: fclean all

.PHONY: all clean bonus flcean re
