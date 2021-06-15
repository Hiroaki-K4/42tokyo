#Makefile
NAME = cub3D

.PHONY: all, clean, fclean, re

SRCS = srcs/main.c srcs/decide_texture.c srcs/map_space_check.c srcs/map_word_check.c srcs/map_check.c srcs/end_process.c srcs/load_texture.c srcs/init_process.c srcs/key_press.c srcs/write_texture.c srcs/ft_utils.c srcs/cub_line_check.c srcs/make_decimal_color.c srcs/convert_int_matrix.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

LIBFT = libft

MLX = mlx_linux

all: $(NAME)

$(NAME):$(SRCS)
		make -C $(LIBFT)
		make -C $(MLX)
		$(CC) $(CFLAGS) $(SRCS) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME)

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
		rm -f libft/libft.a
		rm -f $(NAME)

re: fclean all
