# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoichon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 11:21:27 by agoichon          #+#    #+#              #
#    Updated: 2023/04/11 15:57:51 by agoichon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBMLX	= minilibx-linux

#COMMAND
CC		=	@clang
CFLAGS	=	-g -Wall -Wextra -Werror
IFLAGS	=	-Iinc -I/usr/include -I$(LIBMLX)/include
MLXFLAG	=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
MK		=	@mkdir -p
RM		=	@rm -f
HARDRM	=	@rm -rf
CLEAR	=	@clear
FILE	=	$(shell ls -l src/**/* | grep -F .c | wc -l)
CMP		=	1

# COLOR #
GREEN	=	\033[38;5;76m
RED		=	\033[38;5;124m
YELLOW	=	\033[38;5;226m
ORANGE	=	\033[38;5;202m
PURPLE	=	\033[38;5;213m
LBLUE	=	\033[38;5;51m
BLUE	=	\033[38;5;117m
INDI	=	\033[38;5;99m
RESET	=	\033[00m

P1	=	@printf "\r${RED}   ____ ${GREEN}  __    __ ${YELLOW}  ______ ${ORANGE}  _____ ${PURPLE}   ______    "
P2	=	printf "\n${RED}  / ___) ${GREEN} ) )  ( (  ${YELLOW}(_   _ \ ${ORANGE} )__  \ ${PURPLE} (_  __ \   "
P3	=	printf "\n${RED} / /     ${GREEN}( (    ) ) ${YELLOW}  ) (_) )${ORANGE}  __) / ${PURPLE}   ) ) \ \  "
P4	=	printf "\n${RED}( (      ${GREEN} ) )  ( (  ${YELLOW}  \   _/ ${ORANGE} (__ (  ${PURPLE}  ( (   ) ) "
P5	=	printf "\n${RED}( (      ${GREEN}( (    ) ) ${YELLOW}  /  _ \ ${ORANGE}    \ \ ${PURPLE}   ) )  ) ) "
P6	=	printf "\n${RED} \ \___  ${GREEN} ) \__/ (  ${YELLOW} _) (_) )${ORANGE} ___/  )${PURPLE}  / /__/ /  "
P7	=	printf "\n${RED}  \____) ${GREEN} \______/  ${YELLOW}(______/ ${ORANGE} )____/ ${PURPLE} (______/   ${RESET}\n\n"

HELL	=	$(P1);$(P2);$(P3);$(P4);$(P5);$(P6);$(P7);

#LIBFT
LIBFT_NAME	=	./libft/libft.a
LIBFT_DIR	=	./libft/ --no-print-directory

#MLX
MLX_NAME		=	./minilibx-linux/build/libmlx42.a
MLX_DIR			= 	./minilibx-linux/ --no-print-directory

#SOURCES
SRCS		:=	main.c\
				check_map.c\
				check_params.c\
				init.c\
				utils.c\
				handle.c\


#OBJECTS
OBJS		=	$(addprefix objs/, $(SRCS:%.c=%.o))
OBJS_DIR	=	objs
OBKS_MLX	=	 ${SRCS:.c=.o}

all : $(MLX_NAME) $(LIBFT_NAME) $(NAME)

$(OBJS_DIR)/%.o: %.c
	$(MK) $(@D)
	@printf "\r$(LBLUE)[$(RESET)+$(LBLUE)] $(RESET)Compiling $(GREEN)$<$(BLUE) [$(RESET)$(CMP)$(BLUE)/$(RESET)$(FILE)$(BLUE)]$(RESET)         \r"
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(MLX_NAME):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLXFLAG) $(OBJS) $(LIBFT_NAME) $(MLX_NAME) -o $(NAME)
	@printf "\r                                                                          "
	$(HELL)

$(NAME_B) : $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_NAME) -o $(NAME_B)

clean :
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS_MLX)
#	@rm -f $(LIBMLX)/build
	$(HARDRM) $(OBJS_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(NAME_B)

norme :
	norminette libft
	norminette src
	norminette inc

re : fclean all

fast :
	$(HARDRM) $(OBJS_DIR)
	$(RM) $(NAME) $(NAME_B)
	@make -j
	-./$(NAME) maps/map.cub

run: re
	-./$(NAME) maps/map.cub

.PHONY :
	all clean fclean re
