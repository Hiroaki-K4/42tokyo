#Makefile
NAME = philo

.PHONY: all, clean, fclean, re

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

all: $(NAME)

$(NAME):$(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
