#Makefile
NAME = libftprintf.a

.PHONY: all, clean, fclean, re, bonus

SRCS = ft_printf.c ft_print_char.c ft_print_string.c ft_print_int.c ft_print_percent.c ft_print_unsigned_int.c

# BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

# OBJSBONUS = $(BONUS:.c=.o)

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
