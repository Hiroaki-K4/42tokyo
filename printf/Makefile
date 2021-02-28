#Makefile
NAME = libftprintf.a

.PHONY: all, clean, fclean, re, bonus

SRCS = ft_printf.c

# BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

# OBJSBONUS = $(BONUS:.c=.o)

INCLUDE = -I.

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSBONUS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJSBONUS)

clean:
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all
