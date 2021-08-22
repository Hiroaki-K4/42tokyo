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
./fdf maps/test_maps/elem-fract.fdf
./fdf maps/test_maps/elem.fdf
./fdf maps/test_maps/elem2.fdf
./fdf maps/test_maps/julia.fdf
./fdf maps/test_maps/mars.fdf
./fdf maps/test_maps/pentenegpos.fdf
./fdf maps/test_maps/plat.fdf
./fdf maps/test_maps/pnp_flat.fdf
./fdf maps/test_maps/pylone.fdf
./fdf maps/test_maps/pyra.fdf
./fdf maps/test_maps/pyramide.fdf
./fdf maps/test_maps/t1.fdf
./fdf maps/test_maps/t2.fdf

echo "Error case"
echo "42_1"
./fdf maps/test_maps/42_1.fdf
echo "42_2"
./fdf maps/test_maps/42_2.fdf
echo "42_3"
./fdf maps/test_maps/42_3.fdf
echo "42_4"
./fdf maps/test_maps/42_4.fdf
echo "42_5"
./fdf maps/test_maps/42_5.fdf
echo "42_6"
./fdf maps/test_maps/42_6.fdf
echo "42_7"
./fdf maps/test_maps/42_7.fdf
echo "42_8"
./fdf maps/test_maps/42_8.fdf
echo "42_noper"
chmod 000 maps/test_maps/42_noper.fdf
./fdf maps/test_maps/42_noper.fdf
chmod 777 maps/test_maps/42_noper.fdf
echo "t1_1"
./fdf maps/test_maps/t1_1.fdf
echo "t1_2"
./fdf maps/test_maps/t1_2.fdf
echo "t1_3"
./fdf maps/test_maps/t1_3.fdf
echo "t1_4"
./fdf maps/test_maps/t1_4.fdf
echo "t1_5"
./fdf maps/test_maps/t1_5.fdf
echo "t1_6"
./fdf maps/test_maps/t1_6.fdf
echo "empty"
./fdf maps/test_maps/empty.fdf
echo "incorrect args"
echo "only_0"
./fdf maps/test_maps/only_0.fdf
echo "only_10"
./fdf maps/test_maps/only_10.fdf
./fdf aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
valgrind --log-file="log1.txt" --leak-check=full --show-leak-kinds=all --track-origins=yes ./fdf maps/test_maps/42.fdf | grep "ERROR SUMMARY"
make fclean
cd ..
sh git.sh $*
cd fdf