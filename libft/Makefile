# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:59:47 by auverneu          #+#    #+#              #
#    Updated: 2016/01/03 19:46:12 by auverneu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
INC_PATH = includes
SRC_PATH = srcs
OBJ_PATH = objs
SRC_NAME = ft_isdigit.c \
		   ft_memcmp.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_strdel.c \
		   ft_strlcat.c \
		   ft_strncpy.c \
		   ft_strstr.c \
		   ft_atoi.c \
		   ft_isprint.c \
		   ft_memcpy.c \
		   ft_putendl.c \
		   ft_strcat.c \
		   ft_strdup.c \
		   ft_strlen.c \
		   ft_strnequ.c \
		   ft_strsub.c \
		   ft_bzero.c \
		   ft_itoa.c \
		   ft_memdel.c \
		   ft_putendl_fd.c \
		   ft_strchr.c \
		   ft_strequ.c \
		   ft_strmap.c \
		   ft_strnew.c \
		   ft_strtrim.c \
		   ft_isalnum.c \
		   ft_memalloc.c \
		   ft_memmove.c \
		   ft_putnbr.c \
		   ft_strclr.c \
		   ft_striter.c \
		   ft_strmapi.c \
		   ft_strnstr.c \
		   ft_tolower.c \
		   ft_isalpha.c \
		   ft_memccpy.c \
		   ft_memset.c \
		   ft_putnbr_fd.c \
		   ft_strcmp.c \
		   ft_striteri.c \
		   ft_strncat.c \
		   ft_strrchr.c \
		   ft_toupper.c \
		   ft_isascii.c \
		   ft_memchr.c \
		   ft_putchar.c \
		   ft_putstr.c \
		   ft_strcpy.c \
		   ft_strjoin.c \
		   ft_strncmp.c \
		   ft_strsplit.c \
		   ft_reverse.c \
		   ft_lstdelone.c \
		   ft_lstdel.c \
		   ft_lstnew.c \
		   ft_lstiter.c \
		   ft_lstadd.c \
		   get_next_line.c

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I $(INC_PATH)

.PHONY: re all norme clean fclean

ifndef VERBOSE
.SILENT:
endif

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\e[93m[Creating Libft]:\e[0m\n"
	@printf "%s\n" $@
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%s\n" $@
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@printf "\e[36;4m[Compiling Libft]:\e[0m\n"
	mkdir -p $(OBJ_PATH)

clean:
ifneq ($(wildcard $(OBJ)),)
	@printf "\e[31;4m[Deleting objs Libft]:\e[0m\n"
endif
	@rm -f $(OBJ)
	@rm -rvf $(OBJ_PATH)

fclean: clean
ifneq ($(wildcard $(NAME)),)
	@printf "\e[31;4m[Deleting libft.a]:\e[0m\n"
endif
	@rm -fv $(NAME)

re: fclean all
