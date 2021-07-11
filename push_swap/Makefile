#Makefile
NAME = push_swap

.PHONY: all, clean, fclean, re

SRCS = srcs/main.c srcs/quick_sort.c srcs/quick_sort_utils.c srcs/stack_min_max.c srcs/under_six_sort.c srcs/end_process.c srcs/stack_utils.c srcs/reverse_rotate_operations.c srcs/rotate_operations.c srcs/push_swap_operations.c srcs/init_process.c srcs/error_check.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

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
