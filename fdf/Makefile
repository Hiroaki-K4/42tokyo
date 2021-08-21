#Makefile
NAME = fdf

.PHONY: all, clean, fclean, re

SRCS = srcs/main.c srcs/free.c srcs/get_coords_info.c srcs/draw_line.c srcs/convert_hex_to_dec.c srcs/get_color.c srcs/draw_map.c srcs/read_fdf_file.c srcs/end_process.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_next_line/support.c

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
	rm -f $(OBJS)

fclean: clean
		rm -f libft/libft.a
		rm -f $(NAME)

re: fclean all
