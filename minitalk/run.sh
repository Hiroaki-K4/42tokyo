#!/bin/bash

# make re
gcc server.c -o server
gcc client.c -o client
# make fclean
cd ..
sh git.sh $*
cd minitalk