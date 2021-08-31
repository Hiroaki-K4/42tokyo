#Makefile
NAME = philo_test

.PHONY: all, clean, fclean, re

SRCS = ../ft_utils.c ../init.c test_func.cpp test_main.cpp

TEST_LINK= -lgtest

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME):$(SRCS)
		$(CXX) $(CXXFLAGS) $(SRCS) $(TEST_LINK) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all