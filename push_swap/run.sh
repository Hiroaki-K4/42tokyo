#!/bin/bash

make re
# ./push_swap 1 2 3 4 5
./push_swap 5 1 3 4 2
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 1 2 3 4 5 | grep "ERROR SUMMARY"

make fclean
cd ..
sh git.sh $*
cd push_swap