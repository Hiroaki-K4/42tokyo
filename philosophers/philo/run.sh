#!/bin/bash

make re
./philo 1 1 1 1
make fclean
cd test
make re
./test
make fclean
cd ../../../
sh git.sh $*
cd philosophers/philo