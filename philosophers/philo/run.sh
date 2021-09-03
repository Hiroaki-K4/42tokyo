#!/bin/bash

make re
./philo 3 25000 300 300
make fclean
# cd test
# make re
# ./philo_test
# make fclean
# cd ../../../
cd ../../
sh git.sh $*
cd philosophers/philo