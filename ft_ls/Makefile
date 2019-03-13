# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 18:42:02 by maabou-h          #+#    #+#              #
#    Updated: 2019/02/26 00:04:17 by tmeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs

SRC_NAME = ft_listcreate.c \
		   ft_listdel.c \
		   ft_listfiles.c \
		   ft_listsort.c \
		   ft_ls.c \
		   ft_ls2.c \
		   ft_ls3.c \
		   ft_rwx.c \
		   ft_toolbox.c \
		   ft_toolbox2.c \
		   ft_toolbox3.c \
		   ft_toolbox4.c \

NAME = ft_ls

CC = clang

CFLAGS = -I includes -Werror -Wall -Wextra

OBJ_PATH = .obj

ARG ?= $N

OBJ_NAME = $(SRC_NAME:%.c=%.o)
	OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
	SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ srcs/libftprintf.a -o $@

$(OBJ): includes/ft_ls.h

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rfv $(OBJ_PATH)

fclean: clean
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
