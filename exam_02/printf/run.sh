#!/bin/bash

make re
gcc main.c -L. -lftprintf
echo "~~printf test~~ "
./a.out
cd ../../
sh git.sh
cd exam_02/printf
