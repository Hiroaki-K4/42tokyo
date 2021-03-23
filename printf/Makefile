#Makefile
NAME = libftprintf.a

.PHONY: all, clean, fclean, re, bonus

SRCS = ft_printf.c ft_printf_utils.c ft_print_char.c ft_print_string.c ft_print_int.c ft_print_percent.c ft_print_unsigned_int.c ft_utils.c ft_utils_second.c ft_utils_third.c ft_print_hex.c ft_print_pointer.c

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
