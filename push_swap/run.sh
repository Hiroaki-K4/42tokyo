#!/bin/bash

make re
# ./push_swap 1 2 3 4 5
./push_swap 16 3 11 2 15 8 4 20 18 5 13 19 1 9 17 12 6 7 10 14
# ./push_swap -3185 -7805 -3020 -9648 -1496 -7263 -5934 4705 -1872 9175 -768 -2712 -9031 5410 -3246 3249 -4425 6418 788 4693 6550 -7941 -9657 -4446 3700 5360 -4742 -5580 -8819 -6317 -9272 -2003 -401 -2292 2070 8104 4167 9857 6529 -7706 -7250 -518 -418 -6279 -1388 -9944 -9310 7908 -9806 1479 2600 6745 7259 6664 -3981 958 5744 4998 5379 6926 8681 6107 -1357 -1720 -2465 -5567 104 -8299 -5711 353 -2283 761 -6445 7299 8203 5888 -8924 8894 3795 -8730 4093 115 -8265 5072 -3221 -2246 -250 -7478 -7249 -4872 -6832 -8568 -5045 1811 3433 2491 9965 -6464 7913 -2026
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 1 2 3 4 5 | grep "ERROR SUMMARY"

make fclean
cd ..
sh git.sh $*
cd push_swap