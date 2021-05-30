#!/bin/bash

make re
# ./cub3D sample.cub
./cub3D try.cu
make fclean
cd ..
sh git.sh
cd cub3D