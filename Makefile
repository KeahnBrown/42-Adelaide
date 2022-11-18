# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrown <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 17:10:11 by kbrown            #+#    #+#              #
#    Updated: 2022/09/27 17:10:21 by kbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
FLAGS = -Wall -Werror -Wextra

SOURCE_PATH = sources/
SOURCES = \
	fractol.c\
	init.c\
	draw.c\
	mandelbrot.c\
	julia.c\
	fractal_burning_ship.c\
	fractal_mandelbar.c\
	fractal_celtic_mandelbrot.c\
	fractal_celtic_mandelbar.c\
	fractal_celtic_perpendicular.c\
	fractal_perpendicular_mandelbrot.c\
	fractal_perpendicular_burning_ship.c\
	fractal_perpendicular_buffalo.c\
	colour.c\
	controls_keyboard.c\
	controls_mouse.c\
	controls_utils.c\
	print.c\
	utils.c
SRCS = $(addprefix $(SOURCE_PATH), $(SOURCES))

INCLUDES = ./includes

LIBFT = -Llibft -Ilibft ./libft/libft.a

MLXLIBRARY = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
MINILIBX = mlx

all:
	make -s -C libft
	make -s -C $(MINILIBX)
	$(CC) $(FLAGS) $(SRCS) -I $(INCLUDES) $(LIBFT) $(MLXLIBRARY) -o $(NAME)

clean:

fclean: clean

	make clean -C $(MINILIBX)
	rm -rf $(NAME)

re: fclean all
