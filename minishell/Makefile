# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 13:01:27 by tmeyer            #+#    #+#              #
#    Updated: 2019/03/27 08:15:52 by tmeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs

SRC_NAME = launcher.c \
		   interpretor.c \
		   env.c \
		   env2.c \
		   expantions.c \
		   ft_echo.c \
		   get_command.c \
		   ft_split_whitespaces_m.c \
		   ft_cd.c \
		   exec.c \
		   tools.c \
		   tools3.c

NAME = minishell

CC = clang

CFLAGS = -I includes -I libft/includes -Wall -Wextra -Werror -g3

OBJ_PATH = .obj

OBJ_NAME = $(SRC_NAME:%.c=%.o)
	OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
	SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) libft/libft.a -o $(NAME)

$(OBJ): includes/minishell.h

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rfv $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
