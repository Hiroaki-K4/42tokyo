#!/bin/bash

make re

# ./fdf maps/test_maps/42.fdf
# ./fdf maps/test_maps/10-2.fdf
# ./fdf maps/test_maps/10-70.fdf
# ./fdf maps/test_maps/20-60.fdf
# ./fdf maps/test_maps/50-4.fdf
# ./fdf maps/test_maps/100-6.fdf
# ./fdf maps/test_maps/basictest.fdf
# ./fdf maps/test_maps/elem-col.fdf
# ./fdf maps/test_maps/elem-fract.fdf
# ./fdf maps/test_maps/elem.fdf
# ./fdf maps/test_maps/elem2.fdf
# ./fdf maps/test_maps/julia.fdf
# ./fdf maps/test_maps/mars.fdf
./fdf maps/test_maps/pentenegpos.fdf
# ./fdf maps/test_maps/plat.fdf
# ./fdf maps/test_maps/pnp_flat.fdf
# ./fdf maps/test_maps/pylone.fdf
# ./fdf maps/test_maps/pyra.fdf
# ./fdf maps/test_maps/pyramide.fdf
# ./fdf maps/test_maps/t1.fdf
# ./fdf maps/test_maps/t2.fdf
make fclean
cd ..
sh git.sh $*
cd fdf