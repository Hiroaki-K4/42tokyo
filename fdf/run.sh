#!/bin/bash

make re
./fdf maps/test_maps/42.fdf
./fdf maps/test_maps/10-2.fdf
./fdf maps/test_maps/42.fdf
./fdf maps/test_maps/42.fdf
./fdf maps/test_maps/42.fdf
./fdf maps/test_maps/42.fdf
./fdf maps/test_maps/42.fdf
./fdf maps/test_maps/42.fdf
make fclean
cd ..
sh git.sh $*
cd fdf