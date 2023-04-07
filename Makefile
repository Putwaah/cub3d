NAME = cub3d

#SRC = 

CFLAGS -WALL -Wextra -Werror -I/usr/include -IMLX42 -03

OBJ = $(SRC:.c=.o)

%.o: %.c
	@clang $(CFLAGS) -c $< -o $a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s
	@make -C MLX42 -s
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
