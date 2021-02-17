#!/bin/bash

# for i in `seq 15`
# do
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
# ./a.out sample.txt
# done

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10000 get_next_line.c get_next_line_utils.c test.c
# ./a.out sample.txt

# echo "~~~short_line~~~"
# for i in `seq 15`
# do
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
# ./a.out short.txt
# done

# echo "~~~long_line~~~"
# for i in `seq 15`
# do
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
# ./a.out long.txt
# done

# echo "~~~empty_test~~~"
# for i in `seq 15`
# do
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
# ./a.out empty.txt
# done

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=128 get_next_line.c get_next_line_utils.c test.c
./a.out sample.txt
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c -lsd
# ./a.out long.txt
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c
# ./a.out medium.txt