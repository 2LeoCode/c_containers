NAME = libvector.a
LERROR = src/error/error.a

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f
AR = ar rcs

all: $(NAME)

-include $(DEP)

$(NAME): $(LERROR) $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(LERROR):
	$(MAKE) -C src/error

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEP)
	$(MAKE) -C src/error clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C src/error fclean

re: fclean all

.PHONY: all clean fclean re
