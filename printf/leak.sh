#!/bin/bash

# gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=2000 main_file.c get_next_line.c get_next_line_utils.c
# for i in `seq 6`
# do
make re
gcc main.c -L. -lftprintf
valgrind --log-file="log1.txt" --leak-check=full ./a.out | grep "ERROR SUMMARY"
make re
gcc main2.c -L. -lftprintf
valgrind --log-file="log2.txt" --leak-check=full ./a.out | grep "ERROR SUMMARY"
# done


# for i in `seq 15`
# do
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
# ./a.out long.txt
# done