NAME=libtable.a

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
DEP=$(OBJ:.o=.d)

RM=rm -f
CC=gcc
CFLAGS=-MMD -Wall -Werror -Wextra
LD=ar rcs

RELEASE=false

ifeq ($(RELEASE),true)
	CFLAGS += -O3
endif

all: $(NAME)

-include $(DEP)

release: fclean
	$(MAKE) RELEASE=true

$(NAME): $(OBJ)
	$(LD) $@ $^

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
