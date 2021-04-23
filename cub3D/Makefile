#Makefile
NAME = cub3D

.PHONY: all, clean, fclean, re

SRCS = cub3D.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I.

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

LIBFT = libft

all: $(NAME)

$(NAME):$(SRCS)
		make -C $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
		rm -f libft/libft.a
		rm -f $(NAME)

re: fclean all
