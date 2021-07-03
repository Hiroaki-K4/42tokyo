#!/bin/bash

make re
./push_swap 1 2 3 4 5
valgrind ./push_swap 1 2 3 4 5
make fclean
cd ..
sh git.sh $*
cd push_swap