#!/bin/bash

make re
./push_swap 3 2 a -10 + -0 -- -2147483649
make fclean
cd ..
sh git.sh
cd push_swap