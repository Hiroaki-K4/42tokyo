#!/bin/bash

make re
# # gcc server.c -o server
# # gcc client.c -o client
./server &
# valgrind -s --log-file="log1.txt" --leak-check=full --show-leak-kinds=all --track-origins=yes ./server | grep "ERROR SUMMARY"
pid=$(ps --no-heading -C server -o pid)
./client $pid Hello
# valgrind -s --log-file="log2.txt" --leak-check=full --show-leak-kinds=all --track-origins=yes ./client $pid Hello | grep "ERROR SUMMARY"
# echo ${pid}
kill $pid
make fclean
cd ..
sh git.sh $*
cd minitalk