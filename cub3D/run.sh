#!/bin/bash

make re
./cub3D .cub
# ./cub3D test.cub
make fclean
cd ..
sh git.sh
cd cub3D