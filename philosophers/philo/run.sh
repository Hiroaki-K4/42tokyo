#!/bin/bash

make re
./philo 3 25000 200 500
make fclean
# cd test
# make re
# ./philo_test
# make fclean
# cd ../../../
cd ../../
sh git.sh $*
cd philosophers/philo