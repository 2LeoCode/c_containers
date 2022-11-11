# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:37:07 by Leo Suardi        #+#    #+#              #
#    Updated: 2022/11/10 13:58:14 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcstring.a
TABLE = src/table/libtable.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)

-include $(DEP)

$(NAME): $(TABLE) $(OBJ)
	ranlib $(NAME)

$(TABLE):
	$(MAKE) -C src/table

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@
	$(AR) $(ARFLAGS) $(NAME) $@

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all
