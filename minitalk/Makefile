#Makefile
NAME = minitalk

CLIENT_NAME = client

SERVER_NAME = server

.PHONY: all, clean, fclean, re

CLIENT_SRCS = client.c

SERVER_SRCS = server.c bit_operation.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

LIBFT = libft

all: $(NAME)

$(NAME):$(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME):$(CLIENT_SRCS)
				make -C $(LIBFT)
				$(CC) $(CFLAGS) $(CLIENT_SRCS) libft/libft.a -o $(CLIENT_NAME)

$(SERVER_NAME):$(SERVER_SRCS)
				make -C $(LIBFT)
				$(CC) $(CFLAGS) $(SERVER_SRCS) libft/libft.a -o $(SERVER_NAME)

clean:
	make clean -C $(LIBFT)
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
		rm -f libft/libft.a
		rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all
