#!/bin/bash

make re
./philo 3 899 300 300
# valgrind --tool=helgrind --log-file="log1.txt" --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo 3 899 300 300 | grep "ERROR SUMMARY"
valgrind --tool=helgrind --log-file="log1.txt" --track-origins=yes ./philo 3 899 300 300 | grep "ERROR SUMMARY"
make fclean
# cd test
# make re
# ./philo_test
# make fclean
# cd ../../../
cd ../../
sh git.sh $*
cd philosophers/philo