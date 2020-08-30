# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 13:01:27 by tmeyer            #+#    #+#              #
#    Updated: 2018/11/19 10:42:03 by tmeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

INCLUDE = tests/libfts.h

S_FILES = ft_bzero.s \
		 ft_strcat.s \
		 ft_isalpha.s \
		 ft_isdigit.s \
		 ft_isalnum.s 

S_PATH = srcs

C_FILES = tests/main.c

O_PATH = .obj

SRC = $(addprefix src/, $(S_FILES))

OBJ = $(S_FILES:%.s=.obj/%.o)

FLAGS = -Wall \
		-Werror \
		-Wextra \

all: $(NAME) 

$(O_PATH)/%.o: $(S_PATH)/%.s
	@mkdir -p $(O_PATH)
	@nasm -f macho64 -o $@ $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

test: $(NAME)
	@gcc $(FLAGS) -I $(INCLUDE) $(C_FILES) $(NAME) -o asm

clean: 
	/bin/rm -fr $(O_PATH)

fclean: clean
	/bin/rm -f $(NAME) asm

re: fclean all

.PHONY: clean fclean all re
