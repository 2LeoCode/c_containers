NAME=libtrie.a

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
DEP=$(OBJ:.o=.d)

RM=rm -f
CC=gcc
CFLAGS=-Wall -Werror -Wextra -MMD
LD=ar rcs

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	$(LD) $@ $^

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
