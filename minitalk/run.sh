#!/bin/bash

make re
# # gcc server.c -o server
# # gcc client.c -o client
./server &
# valgrind -s --log-file="log1.txt" --leak-check=full --show-leak-kinds=all --track-origins=yes ./server | grep "ERROR SUMMARY"
pid=$(ps --no-heading -C server -o pid)
# ./client $pid Hello
./client $pid
./client ccc
./client $pid E5wV7FcZ3e5aZUSWbhEmfKCDBc8WQNCfwzrTBp527HLVwGCU2rVYUBJieMb7EWdRF4rt2VTUGtf6bCk58yApYXdRrXf8tYQtW8nKQBasUdssasMgQATL2kDhLhhf45c6yLp8Ly5ApRY9XZFBTHgizpUaFVyKsnHK3mshZX29Qyy9gXjM3RW5w36yjPnXFuYw7ZGunsHxGZCjxVmGwpAVNUChe4EgDTmtuBcC7BwAe94apQZ84rBNUAa2T262hHVDBmwDEKduEUd8sDSN45zjGHeNZRMbRjkVLncJbYeX5hZPrrkw2HVF4a7Rbthek7DVNdGE6fX8bK6zRCeAgV5GT9L8V7XEkibRbLZ75PG4uHzVmMbA4AHj365zRr2pURcgP6t9jDQNaxpCZue4AtkrgKPgKQzuEid38BJsjbp6HyrgAGhMP2yDuTfEwRFabXNTU7w3En8GYkePTfDV7ZPJQnheQi7iARLjthHxrKz5dAmpZ2hMmJta
# valgrind -s --log-file="log2.txt" --leak-check=full --show-leak-kinds=all --track-origins=yes ./client $pid Hello | grep "ERROR SUMMARY"
# echo ${pid}
kill $pid
make fclean
cd ..
sh git.sh $*
cd minitalk