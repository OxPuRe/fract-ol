# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 18:24:41 by auverneu          #+#    #+#              #
#    Updated: 2020/04/24 15:32:23 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
SRC_PATH = srcs
OBJ_PATH = objs
INC = -I./usr/local/include -I./libft/includes -I./includes -I./minilibx-linux

CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lXext -lX11 -lm -lbsd

SRC_NAME = main.c \
		   key_r.c \
		   expose_hook.c \
		   mouse_hook.c \
		   pointer_motion.c \
		   image_pixel_put.c \
		   mandelbrot.c \
		   julia.c \
		   burning_ship.c \
		   loop_hook.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIBFT_PATH = libft/libft.a

MINILIBX_PATH = minilibx-linux/libmlx_Linux.a

.PHONY: all clean fclean re

ifndef VERBOSE
.SILENT:
endif

all: $(NAME)

$(NAME): $(OBJ)
	printf "\e[36;4m[Compiling Minilibx-linux]:\e[0m\n"
	make -C minilibx-linux/
	make -C libft/
	printf "\e[92m[Linking Fract-ol]:\e[0m\n"
	printf "%s\n" $@
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft -L/usr/local/lib/ -lm -L./minilibx-linux -lmlx -lXext -lX11 -lbsd

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	printf "%s\n" $@
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH):
	printf "\e[36;4m[Compiling Fract-ol]:\e[0m\n"
	mkdir -p $(OBJ_PATH)

clean:
ifneq ($(wildcard $(OBJ)),)
	printf "\e[31;4m[Deleting objs Fract-ol]:\e[0m\n"
endif
	rm -f $(OBJ)
	rm -rvf $(OBJ_PATH)
	make -C libft/ clean

fclean: clean
ifneq ($(wildcard $(NAME)),)
	printf "\e[31;4m[Deleting Fract-ol]:\e[0m\n"
endif
	rm -fv $(NAME)
	make -C libft/ fclean

re: fclean all
