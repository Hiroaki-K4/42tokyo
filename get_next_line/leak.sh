#!/bin/bash

gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=2000 main_file.c get_next_line.c get_next_line_utils.c
for i in `seq 6`
do
valgrind --log-file="log$i.txt" --leak-check=full ./a.out test_00$i.txt 2>&1 | grep "ERROR SUMMARY"
done


# for i in `seq 15`
# do
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
# ./a.out long.txt
# done