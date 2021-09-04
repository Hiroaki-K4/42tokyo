#Makefile
NAME = philo

.PHONY: all, clean, fclean, re

SRCS = main.c utils.c init.c eating.c sleep_think.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME):$(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
