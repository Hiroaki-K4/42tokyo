#!/bin/bash

gcc -c ft_printf.c && ar rc libftprintf.a ft_printf.o
cd pft_exam
make
./test
cd ../
cd ../../
sh git.sh
cd exam_02/ft_printf
