# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseng <oseng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 10:17:30 by oseng             #+#    #+#              #
#    Updated: 2018/05/01 14:15:56 by oseng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Load_OBJ
# http://www.opengl-tutorial.org/fr/beginners-tutorials/tutorial-7-model-loading/

NAME 		= scop
CC 	 		= gcc -Wall -Wextra -Werror
LIBS		= -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
SRC  		= main.c \

OBJ  		= $(SRC:%.c=objs/%.o)
SRC_DIR 	= ./srcs/
INCLUDE_DIR = -I ./incs/ -I libft/includes -I minilibx_macos/

all: objs $(NAME)

objs:
	@mkdir objs

$(NAME): $(OBJ)
	@echo "by 😉seng___  ___ ___  _ __  SCOP"
	make -C libft/ all
	make -sC ./minilibx_macos/ all
	$(CC) -o $(NAME) $(OBJ) $(LIBS) minilibx_macos/mlx_opengl.m

objs/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCLUDE_DIR) -o $@ -c $<

clean:
	rm -rf objs
	make clean -C libft/
	make -sC minilibx_macos/ clean

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/
	make -sC minilibx_macos/ clean

re: fclean all

.PHONY: all clean fclean re
