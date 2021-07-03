#!/bin/bash

# make re
# gcc main.c -L. -lftprintf
# echo "~~printf test~~ "
# ./a.out
gcc ft_printf.c test.c -o ft_printf
./ft_printf
valgrind --leak-check=full ./ft_printf | grep "ERROR SUMMARY"
# cat yy
# cat -e yy > y
# gcc -Wall -Werror -Wextra -D REAL main.c -o printf
# ./printf | cat -e > r
# echo "~~~~~~~~~~~diff~~~~~~~~~~~"
# diff -y --suppress-common-lines r y
# rm -rf yy y r ft_printf printf
cd ../../
sh git.sh $*
cd exam_02/ft_printf
