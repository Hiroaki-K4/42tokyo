#!/bin/bash

make re
./cub3D sample.cu
# ./cub3D try.cub
make fclean
cd ..
sh git.sh
cd cub3D