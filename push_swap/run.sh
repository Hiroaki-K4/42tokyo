#!/bin/bash

make re
# ./push_swap 1 2 3 4 5
./push_swap 1 3 2 8 4 5 9 6 7 
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 1 2 3 4 5 | grep "ERROR SUMMARY"

make fclean
cd ..
sh git.sh $*
cd push_swap