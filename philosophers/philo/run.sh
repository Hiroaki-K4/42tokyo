#!/bin/bash

make re
./philo 3 2500000000 200 200
make fclean
# cd test
# make re
# ./philo_test
# make fclean
# cd ../../../
cd ../../
sh git.sh $*
cd philosophers/philo