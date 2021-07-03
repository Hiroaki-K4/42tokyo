#Makefile
NAME = push_swap

.PHONY: all, clean, fclean, re

SRCS = main.c end_process.c list_process.c

OBJS = $(SRCS:.c=.o)

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
	rm -f $(OBJS)

fclean: clean
		rm -f libft/libft.a
		rm -f $(NAME)

re: fclean all
