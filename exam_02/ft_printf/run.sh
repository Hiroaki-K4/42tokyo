#!/bin/bash

# make re
# gcc main.c -L. -lftprintf
# echo "~~printf test~~ "
# ./a.out
gcc -Wall -Werror -Wextra ft_printf.c main.c -o ft_printf
cd ../../
sh git.sh
cd exam_02/printf
