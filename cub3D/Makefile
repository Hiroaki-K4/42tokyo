#Makefile
NAME = cub3D

.PHONY: all, clean, fclean, re

SRCS = main.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I.

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

LIBFT = libft

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o) 

all: $(NAME)

$(NAME):$(OBJS)
		make -C $(LIBFT)
		cp libft/libft.a $(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSBONUS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJSBONUS)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
		rm -f libft/libft.a
		rm -f $(NAME)

re: fclean all
