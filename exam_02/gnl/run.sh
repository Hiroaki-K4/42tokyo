#!/bin/bash

# for i in `seq 15`
# do
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
# ./a.out sample.txt
# done

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10000 get_next_line.c get_next_line_utils.c test.c
# ./a.out sample.txt sample2.txt

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

# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c test.c
# ./a.out main1.c
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c test.c
# ./a.out long.txt
# gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c test.c
# ./a.out medium.txt

gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=2 main_file.c get_next_line.c get_next_line_utils.c
echo "~~test_001.txt~~"
./a.out test_001.txt
echo "~~test_002.txt~~"
./a.out test_002.txt
echo "~~test_003.txt~~"
./a.out test_003.txt
echo "~~test_004.txt~~"
./a.out test_004.txt
echo "~~test_005.txt~~"
./a.out test_005.txt
echo "~~test_006.txt~~"
./a.out test_006.txt
echo "~~none.txt~~"
./a.out none.txt
# gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=3 main_file.c get_next_line.c get_next_line_utils.c
# echo "~~test_001.txt~~"
# ./a.out test_001.txt
# echo "~~test_002.txt~~"
# ./a.out test_002.txt
# echo "~~test_003.txt~~"
# ./a.out test_003.txt
# echo "~~test_004.txt~~"
# ./a.out test_004.txt
# echo "~~test_005.txt~~"
# ./a.out test_005.txt
# echo "~~test_006.txt~~"
# ./a.out test_006.txt
# echo "~~none.txt~~"
# ./a.out none.txt
# gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=4 main_file.c get_next_line.c get_next_line_utils.c
# echo "~~test_001.txt~~"
# ./a.out test_001.txt
# echo "~~test_002.txt~~"
# ./a.out test_002.txt
# echo "~~test_003.txt~~"
# ./a.out test_003.txt
# echo "~~test_004.txt~~"
# ./a.out test_004.txt
# echo "~~test_005.txt~~"
# ./a.out test_005.txt
# echo "~~test_006.txt~~"
# ./a.out test_006.txt
# echo "~~none.txt~~"
# ./a.out none.txt
# gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=2000 main_file.c get_next_line.c get_next_line_utils.c
# echo "~~test_001.txt~~"
# ./a.out test_001.txt
# echo "~~test_002.txt~~"
# ./a.out test_002.txt
# echo "~~test_003.txt~~"
# ./a.out test_003.txt
# echo "~~test_004.txt~~"
# ./a.out test_004.txt
# echo "~~test_005.txt~~"
# ./a.out test_005.txt
# echo "~~test_006.txt~~"
# ./a.out test_006.txt
# echo "~~none.txt~~"
# ./a.out none.txt

# echo "~~Bonus check~~"
# gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=2 main_file.c get_next_line_bonus.c get_next_line_utils_bonus.c
# echo "~~test_001.txt~~"
# ./a.out test_001.txt
# echo "~~test_002.txt~~"
# ./a.out test_002.txt
# echo "~~test_003.txt~~"
# ./a.out test_003.txt
# echo "~~test_004.txt~~"
# ./a.out test_004.txt
# echo "~~test_005.txt~~"
# ./a.out test_005.txt
# echo "~~test_006.txt~~"
# ./a.out test_006.txt
# echo "~~none.txt~~"
# ./a.out none.txt

# echo "~~Stdin check~~"
# gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=2 main_stdin.c get_next_line.c get_next_line_utils.c
# ./a.out
cd ../../
sh git.sh
cd exam_02/gnl