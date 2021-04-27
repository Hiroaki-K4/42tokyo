#!/bin/bash

make re
./cub3D sample.cub
make fclean
cd ..
sh git.sh
cd cub3D