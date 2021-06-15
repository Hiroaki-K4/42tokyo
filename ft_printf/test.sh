#!/bin/bash

make re
gcc main2.c -L. -lftprintf
echo "~~printf test~~ "
./a.out
