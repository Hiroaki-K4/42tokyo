#!/bin/bash

make re
./fdf maps/test_maps/42.fdf
./fdf maps/test_maps/10-2.fdf
./fdf maps/test_maps/10-70.fdf
./fdf maps/test_maps/20-60.fdf
./fdf maps/test_maps/50-4.fdf
./fdf maps/test_maps/100-6.fdf
./fdf maps/test_maps/basictest.fdf
./fdf maps/test_maps/elem-col.fdf
make fclean
cd ..
sh git.sh $*
cd fdf