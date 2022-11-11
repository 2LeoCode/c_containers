NAME=libarray.a

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
DEP=$(OBJ:.o=.d)

RM=rm -f
CC=gcc
CFLAGS=-MMD -Wall -Werror -Wextra
LD=ar rcs

ifeq ($(DEBUG),true)
	CFLAGS += -g
endif

ifeq ($(RELEASE),true)
	CFLAGS += -O3
endif

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	$(LD) $@ $^

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: fclean
	$(MAKE) DEBUG=true

release: fclean
	$(MAKE) RELEASE=true

.PHONY: all clean fclean re debug release
