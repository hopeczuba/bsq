# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwilliam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/03 15:18:18 by jwilliam          #+#    #+#              #
#    Updated: 2016/08/03 15:19:34 by jwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = gcc

SRC =	find_bsq.c \
		first_line.c \
		integer_array.c \
		main.c \
		string_array.c \
		ft_atoi.c \
		ft_putstr.c \
		errors.c

HEADER = bsq.h

FLAGS = -Wall -Wextra -Werror

.PHONY = all clean fclean re

all : $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(FLAGS) $(SRC) -I $(HEADER)

clean:
	/bin/rm -f find_bsq.o first_line.o integer_array.o main.o string_array.o

fclean:
	/bin/rm -f $(NAME)

re: fclean all
