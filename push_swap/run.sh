#!/bin/bash

make re
./push_swap 3
make fclean
cd ..
sh git.sh
cd push_swap