#!/bin/bash

make re
./push_swap 3 2 a 10    
make fclean
cd ..
sh git.sh
cd push_swap