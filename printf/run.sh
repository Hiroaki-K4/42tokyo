#!/bin/bash

make re
gcc main.c -L. -lftprintf
echo "~~printf test~~ "
./a.out
sh git_run.sh