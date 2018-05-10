# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 11:51:45 by pnardozi          #+#    #+#              #
#    Updated: 2017/11/22 14:45:56 by pnardozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = fillit

SRC = main.c \
	  solver.c \
	  map.c \
	  list.c \
	  read.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

INCLUDES = includes/

RED = \033[31m
GREEN = \033[32m
END = \033[0m

all : $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC) -I $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "$(GREEN)FILLIT READY$(END)"

clean:
	/bin/rm -f $(OBJ)
	@echo "$(RED)FILLIT OBJECTS REMOVE$(END)"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "$(RED)FILLIT REMOVE$(END)"

re: fclean all
