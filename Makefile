# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oem <oem@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 20:38:45 by oem               #+#    #+#              #
#    Updated: 2020/07/24 17:59:43 by oem              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
C_FLAGS = -g -Wall -Wextra -Werror
OBJ = main.o check.o mandelbrot.o khook.o
libft = libft -lft
minilibx = minilibx_macos -lmlx_Linux -lXext -lX11
POST_FLAGS = -lm

all: $(NAME)
	$(CC) -o $(NAME) $(C_FLAGS) $(OBJ) -L $(libft) -L $(minilibx) $(POST_FLAGS)
$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx_macos 
%.o: %.c
	$(CC) $(C_FLAGS) -o $@ -c $<
clean:
	make clean -C ./libft 
	rm -rf minilibx_macos/*.o
fclean: clean
	make fclean -C ./libft
	make clean -C ./minilibx_macos
	rm -rf $(OBJ)
	rm -rf $(NAME)
re: fclean all
