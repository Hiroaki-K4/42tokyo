#!/bin/bash

make re
./philo 3 200 200 200
make fclean
cd test
make re
./philo_test
make fclean
cd ../../../
sh git.sh $*
cd philosophers/philo