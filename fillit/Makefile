# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/05 13:26:16 by maabou-h          #+#    #+#              #
#    Updated: 2018/12/09 15:00:47 by maabou-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = block.c helper.c list.c msg.c parse.c solve3.c ft_ft.c

OBJ = block.o helper.o list.o msg.o parse.o solve3.o ft_ft.o

HDR = includes/fillit.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean fclean re

clean: $(OBJ)
		@rm -rf $^

fclean: clean
		@rm -rf $(NAME)

re: fclean all
