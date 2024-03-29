#!/bin/bash

make re
./philo 3 899 300 300 3
# ./philo 3 4294967296 300 300 3
valgrind --log-file="log_leak.txt" --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo 3 899 300 300 3 | grep "ERROR SUMMARY"
valgrind --tool=helgrind --log-file="log_thread.txt" ./philo 3 899 400 300 3 | grep "ERROR SUMMARY"
make fclean
# cd test
# make re
# ./philo_test
# make fclean
# cd ../../../
cd ../../
sh git.sh $*
cd philosophers/philo