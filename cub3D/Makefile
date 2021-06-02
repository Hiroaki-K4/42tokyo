#Makefile
NAME = cub3D

.PHONY: all, clean, fclean, re

SRCS = main.c map_check.c end_process.c load_texture.c init_process.c draw_sprite.c key_press.c write_texture.c ft_utils.c cub_line_check.c make_decimal_color.c convert_int_matrix.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

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
