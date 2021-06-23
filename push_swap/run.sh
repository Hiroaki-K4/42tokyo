#!/bin/bash

make re
./push_swap a
make fclean
cd ..
sh git.sh
cd push_swap