# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 18:24:41 by lnieto-m          #+#    #+#              #
#    Updated: 2020/04/24 15:32:23 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

SRC_PATH = srcs

OBJ_PATH = obj

INC = -I./usr/local/include -I./libft/includes -I./includes -I./minilibx-linux

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lXext -lX11 -lm -lbsd

NAME = fractol

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

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx-linux/
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft -L/usr/local/lib/ -lm -L./minilibx-linux -lmlx -lXext -lX11 -lbsd

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

norme:
	@echo "* Norme fractol"
	norminette $(SRC_NAME)
	@echo "* Norme Libft"
	make -C libft/ norme

.PHONY: clean fclean re all
