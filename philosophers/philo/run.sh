#!/bin/bash

make re
./philo 3 900 300 400 3
make fclean
# cd test
# make re
# ./philo_test
# make fclean
# cd ../../../
cd ../../
sh git.sh $*
cd philosophers/philo