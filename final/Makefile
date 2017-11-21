# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobion <arobion@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 17:04:16 by arobion           #+#    #+#              #
#    Updated: 2017/11/18 17:25:29 by arobion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = cc

CFLAGS = -Werror -Wall -Wextra

NAME = fillit

SRCS = *.c

OBJ = $(SRC:.c=.o)

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRCS) $(INCLUDES)

clean:
	/bin/rm -rf 

