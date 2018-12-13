# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 06:56:45 by tmeyer            #+#    #+#              #
#    Updated: 2018/11/08 11:10:59 by tmeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = 	srcs/ft_putchar.c \
			srcs/ft_putstr.c \
			srcs/ft_swap.c \
			srcs/ft_strlen.c \
			srcs/ft_strcmp.c 

OBJECTS =	ft_putchar.o \
			ft_putstr.o \
			ft_swap.o \
			ft_strlen.o \
			ft_strcmp.o 

FLAGS = -Wall \
		-Werror \
		-Wextra

SOURCEf = srcs/

SOURCEh = includes/

all : $(NAME)

$(NAME) :
		gcc $(FLAGS) -c $(FILES) -I $(SOURCEh)
		ar rc $(NAME) $(OBJECTS)

clean :
		/bin/rm -f $(OBJECTS)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
