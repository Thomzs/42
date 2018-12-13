# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 09:12:57 by tmeyer            #+#    #+#              #
#    Updated: 2018/11/08 11:39:36 by tmeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_display_file

FILES =	displayer.c

OBJECTS = $(FILES:.c=.o)

FLAGS =	-Wall \
		-Werror \
		-Wextra

all : $(NAME)

$(NAME) : 
		gcc -c $(FILES) $(FLAGS)
		gcc $(OBJECTS) -o $(NAME)

clean :
		/bin/rm -f $(OBJECTS)

fclean : clean
		/bin/rm -f $(NAME)
