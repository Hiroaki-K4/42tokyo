#Makefile
NAME = cub3D

.PHONY: all, clean, fclean, re

SRCS = cub3D.c draw_sprite.c save_bmp.c key_press.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

# INCLUDE = -I. -I./libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

LIBFT = libft

all: $(NAME)

$(NAME):$(SRCS)
		make -C $(LIBFT)
		$(CC) $(SRCS) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
		rm -f libft/libft.a
		rm -f $(NAME)

re: fclean all
