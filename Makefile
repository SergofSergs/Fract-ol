# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 20:38:45 by oem               #+#    #+#              #
#    Updated: 2020/08/05 17:36:32 by pjoseth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
C_FLAGS = -g -Wall -Wextra -Werror
OBJ = main.o check.o mandelbrot.o khook.o zoom.o
libft = libft -lft
minilibx = minilibx_macos -lmlx_Linux -lXext -lX11
POST_FLAGS = -lm -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Making libs..."
	@make -s -C ./libft
	@make -s -C ./minilibx_macos
	@$(CC) -o $(NAME) $(C_FLAGS) $(OBJ) -L $(libft) -L $(minilibx) $(POST_FLAGS)
	@echo "./fractol created"
	@echo "Usage: ./fractol FRACTAL_NAME"
	@echo "Avalible names: mandelbrot, julia and burning_ship"
%.o: %.c
	@$(CC) $(C_FLAGS) -o $@ -c $<
clean:
	@make clean -s -C ./libft 
	@rm -rf minilibx_macos/*.o
	@rm -rf $(OBJ)
	@echo "O-files deleted"
fclean: clean
	@make fclean -s -C ./libft
	@make clean -s -C ./minilibx_macos
	@rm -rf $(NAME)
	@echo "Full cleaned"
re: fclean all
