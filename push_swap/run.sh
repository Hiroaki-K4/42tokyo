#!/bin/bash

make re
# ./push_swap 1 2 3 4 5
# ./push_swap 3 2 8 4 5 1 9 6 7 
./push_swap  594 -605 2596 570 3185 -243 1980 1376 33 2146 1098 2690 2214 1924 -382 -542 1626 3489 815 3475 -375 -550 2981 1383 -131 2182 789 355 208 1403 -432 1450 2278 3644 3500 1815 -247 2665 376 434 1995 2122 -524 562 398 574 668 3504 415 2963 -133 1520 3061 3496 3551 3578 2862 1525 1117 -578 3576 1333 2352 3038 1329 3037 1206 1730 2054 3062 3644 401 1536 304 1611 3414 1527 -537 -194 3422 3074 321 2127 3319 1001 2862 -215 1047 739 1550 1118 1499 67 654 1722 2876 43 3576 1790 3577
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 1 2 3 4 5 | grep "ERROR SUMMARY"

make fclean
cd ..
sh git.sh $*
cd push_swap