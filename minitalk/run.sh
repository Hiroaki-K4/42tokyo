#!/bin/bash

make re
# # gcc server.c -o server
# # gcc client.c -o client
./server &
ps --no-heading -C server -o pid
./client pid Hello
# echo ${pid}
# kill ${pid}
make fclean
cd ..
sh git.sh $*
cd minitalk
echo "aaa"