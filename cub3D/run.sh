#!/bin/bash

make re
./cub3D .cub
# ./cub3D try.cub
make fclean
cd ..
sh git.sh
cd cub3D