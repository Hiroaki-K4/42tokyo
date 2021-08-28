#!/bin/bash

make re


make fclean
cd ../../
sh git.sh $*
cd philosophers/philo