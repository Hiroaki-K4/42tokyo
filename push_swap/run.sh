#!/bin/bash

make re
# ./push_swap 1 2 3 4 5
# ./push_swap 4 5 2 3 1 6
# ARG="4 5 2 3 1 6"; ./push_swap $ARG | wc -l
# ARG="4 5 2 3 1 6"; ./push_swap $ARG | ./checker $ARG
# ./push_swap 4 5 2 3 8 1 6 7
# ./push_swap 16 3 11 2 15 8 4 20 18 5 13 19 1 9 17 12 6 7 10 14
# ./push_swap 16 3 11 2 15 8
# ./push_swap -3185 -7805 -3020 -9648 -1496 -7263 -5934 4705 -1872 9175 -768 -2712 -9031 5410 -3246 3249 -4425 6418 788 4693 6550 -7941 -9657 -4446 3700 5360 -4742 -5580 -8819 -6317 -9272 -2003 -401 -2292 2070 8104 4167 9857 6529 -7706 -7250 -518 -418 -6279 -1388 -9944 -9310 7908 -9806 1479 2600 6745 7259 6664 -3981 958 5744 4998 5379 6926 8681 6107 -1357 -1720 -2465 -5567 104 -8299 -5711 353 -2283 761 -6445 7299 8203 5888 -8924 8894 3795 -8730 4093 115 -8265 5072 -3221 -2246 -250 -7478 -7249 -4872 -6832 -8568 -5045 1811 3433 2491 9965 -6464 7913 -2026
# ARG="-3185 -7805 -3020 -9648 -1496 -7263 -5934 4705 -1872 9175 -768 -2712 -9031 5410 -3246 3249 -4425 6418 788 4693 6550 -7941 -9657 -4446 3700 5360 -4742 -5580 -8819 -6317 -9272 -2003 -401 -2292 2070 8104 4167 9857 6529 -7706 -7250 -518 -418 -6279 -1388 -9944 -9310 7908 -9806 1479 2600 6745 7259 6664 -3981 958 5744 4998 5379 6926 8681 6107 -1357 -1720 -2465 -5567 104 -8299 -5711 353 -2283 761 -6445 7299 8203 5888 -8924 8894 3795 -8730 4093 115 -8265 5072 -3221 -2246 -250 -7478 -7249 -4872 -6832 -8568 -5045 1811 3433 2491 9965 -6464 7913 -2026"; ./push_swap $ARG | wc -l
# ARG="-3185 -7805 -3020 -9648 -1496 -7263 -5934 4705 -1872 9175 -768 -2712 -9031 5410 -3246 3249 -4425 6418 788 4693 6550 -7941 -9657 -4446 3700 5360 -4742 -5580 -8819 -6317 -9272 -2003 -401 -2292 2070 8104 4167 9857 6529 -7706 -7250 -518 -418 -6279 -1388 -9944 -9310 7908 -9806 1479 2600 6745 7259 6664 -3981 958 5744 4998 5379 6926 8681 6107 -1357 -1720 -2465 -5567 104 -8299 -5711 353 -2283 761 -6445 7299 8203 5888 -8924 8894 3795 -8730 4093 115 -8265 5072 -3221 -2246 -250 -7478 -7249 -4872 -6832 -8568 -5045 1811 3433 2491 9965 -6464 7913 -2026"; ./push_swap $ARG | ./checker $ARG
./push_swap -125 -8527 -4802 7761 -3957 3438 14057 -5213 2731 7551 -15044 16614 17353 18378 8719 -4094 21414 -30 -5342 -21282 17016 -7723 17879 13942 -9168 -13218 -3239 -16421 -14744 19962 2194 6605 -739 18866 2192 16778 829 -5225 -608 -17914 -9848 15123 -13474 -13970 21327 -16928 3410 21266 4516 19542 -12190 9358 -355 -15786 1826 11952 -7530 20061 17005 8501 -15100 7025 -6368 14937 4416 -16350 10240 -6928 9200 -2542 5933 20826 -8894 13933 -14619 259 -15169 19566 50 10821 -16014 18635 8006 5105 -18625 -11643 4883 4620 -3756 9714 -8353 2619 -4736 16054 5382 -12493 21178 -5853 2053 8904 -20568 -4188 17556 1313 -11730 -9236 -19902 -5424 -11145 10923 -6777 3616 8084 -10945 -12753 10933 -1114 -20044 3379 16605 11145 16500 7050 -15066 11079 -9043 -6085 20084 15879 -16206 16814 16785 1080 12895 -3376 20126 -8515 7497 -6773 1815 -3055 17225 -16044 -16446 -15194 1978 -17687 14467 3409 7167 18898 -6921 2192 4473 8788 1098 -16744 -9470 9008 -13038 -4202 4347 -17728 18353 5068 9671 17004 -15620 -4307 -1943 7669 -19535 3108 -20549 -14507 18689 12205 -10719 11682 3440 17922 9105 -15655 7940 1405 14607 -3136 6135 -16338 -15603 14571 10236 19519 -15330 7114 12414 -17833 11944 18268 8636 -2173 13763 10575 -20540 -18960 17542 19624 -18929 -5351 19132 5985 397 16063 11804 -13137 -4007 14238 14502 -10045 -14274 -13274 -7648 17436 -5929 -1504 12376 -14990 11439 2845 -8896 -1400 -20803 -7307 -2999 -10567 4509 2369 -12418 7054 18493 -5460 866 -2585 -10872 -8805 15053 6596 -6741 8081 -15623 460 -17367 -1797 5722 -1822 18174 -3376 4663 17439 20943 -16407 3865 -12033 7062 -20609 -1126 -9904 12535 17231 -15024 18854 -9704 7316 4096 10199 -13662 -2326 4621 1071 -6419 10472 -10643 -2312 -12799 16554 17341 -6799 1004 9830 -10835 472 -18751 -19144 19214 9785 -8978 -3387 -12293 -17918 -7631 -5842 -20538 13440 -20001 5032 2165 -2888 -9468 -5388 -13990 14889 -16390 6142 -8898 -7715 1221 -3731 16261 -19250 -6075 -6748 11998 -3351 -4418 9737 -5740 8078 -5823 3442 20935 8020 19074 -11777 9287 -13101 -18919 -722 5486 -6912 15364 -20678 -4197 -13200 6938 17680 9860 -4014 -7525 4646 7511 17175 19372 -1966 -7651 2780 -4402 8084 -10617 11249 -9949 -1855 7095 -3049 7842 4208 14625 10398 -17989 -1364 -8688 -14798 8733 8589 -6524 -5803 4794 -8837 11657 -14905 17283 -2307 -19204 -18467 -16446 -5381 5787 9927 -9471 -17003 -299 11355 11917 -5378 -3868 -1716 20305 -10717 -12793 -9858 18694 9294 -3182 5953 -3592 21070 -21325 -10971 -9242 21107 -4402 -4133 6626 7169 -1126 20955 -19686 -7512 9407 1618 6260 -3066 800 -3298 13031 18406 16460 21162 -13786 -8506 -10171 -16566 -20687 17423 10861 6497 17018 20311 17000 -4398 -13705 424 12943 -19253 -13881 -9657 -19772 -2792 13606 11109 -13348 -1609 -4130 8926 16567 -3273 5858 20853 -3586 -20102 -9128 7717 -15194 961 3665 -16507 -4716 8509 -17671 110 -17364 -601 -20941 -16594 1621 -4047 4524 3323 -19013 -3345 2258 -10886 16520 -14046 -14134 20913 4155 13198 20291 -20906 14571 -1010 17587 -12797 -12223 9078 -7829 4535 -3887 5275 -16830
# ARG="-125 -8527 -4802 7761 -3957 3438 14057 -5213 2731 7551 -15044 16614 17353 18378 8719 -4094 21414 -30 -5342 -21282 17016 -7723 17879 13942 -9168 -13218 -3239 -16421 -14744 19962 2194 6605 -739 18866 2192 16778 829 -5225 -608 -17914 -9848 15123 -13474 -13970 21327 -16928 3410 21266 4516 19542 -12190 9358 -355 -15786 1826 11952 -7530 20061 17005 8501 -15100 7025 -6368 14937 4416 -16350 10240 -6928 9200 -2542 5933 20826 -8894 13933 -14619 259 -15169 19566 50 10821 -16014 18635 8006 5105 -18625 -11643 4883 4620 -3756 9714 -8353 2619 -4736 16054 5382 -12493 21178 -5853 2053 8904 -20568 -4188 17556 1313 -11730 -9236 -19902 -5424 -11145 10923 -6777 3616 8084 -10945 -12753 10933 -1114 -20044 3379 16605 11145 16500 7050 -15066 11079 -9043 -6085 20084 15879 -16206 16814 16785 1080 12895 -3376 20126 -8515 7497 -6773 1815 -3055 17225 -16044 -16446 -15194 1978 -17687 14467 3409 7167 18898 -6921 2192 4473 8788 1098 -16744 -9470 9008 -13038 -4202 4347 -17728 18353 5068 9671 17004 -15620 -4307 -1943 7669 -19535 3108 -20549 -14507 18689 12205 -10719 11682 3440 17922 9105 -15655 7940 1405 14607 -3136 6135 -16338 -15603 14571 10236 19519 -15330 7114 12414 -17833 11944 18268 8636 -2173 13763 10575 -20540 -18960 17542 19624 -18929 -5351 19132 5985 397 16063 11804 -13137 -4007 14238 14502 -10045 -14274 -13274 -7648 17436 -5929 -1504 12376 -14990 11439 2845 -8896 -1400 -20803 -7307 -2999 -10567 4509 2369 -12418 7054 18493 -5460 866 -2585 -10872 -8805 15053 6596 -6741 8081 -15623 460 -17367 -1797 5722 -1822 18174 -3376 4663 17439 20943 -16407 3865 -12033 7062 -20609 -1126 -9904 12535 17231 -15024 18854 -9704 7316 4096 10199 -13662 -2326 4621 1071 -6419 10472 -10643 -2312 -12799 16554 17341 -6799 1004 9830 -10835 472 -18751 -19144 19214 9785 -8978 -3387 -12293 -17918 -7631 -5842 -20538 13440 -20001 5032 2165 -2888 -9468 -5388 -13990 14889 -16390 6142 -8898 -7715 1221 -3731 16261 -19250 -6075 -6748 11998 -3351 -4418 9737 -5740 8078 -5823 3442 20935 8020 19074 -11777 9287 -13101 -18919 -722 5486 -6912 15364 -20678 -4197 -13200 6938 17680 9860 -4014 -7525 4646 7511 17175 19372 -1966 -7651 2780 -4402 8084 -10617 11249 -9949 -1855 7095 -3049 7842 4208 14625 10398 -17989 -1364 -8688 -14798 8733 8589 -6524 -5803 4794 -8837 11657 -14905 17283 -2307 -19204 -18467 -16446 -5381 5787 9927 -9471 -17003 -299 11355 11917 -5378 -3868 -1716 20305 -10717 -12793 -9858 18694 9294 -3182 5953 -3592 21070 -21325 -10971 -9242 21107 -4402 -4133 6626 7169 -1126 20955 -19686 -7512 9407 1618 6260 -3066 800 -3298 13031 18406 16460 21162 -13786 -8506 -10171 -16566 -20687 17423 10861 6497 17018 20311 17000 -4398 -13705 424 12943 -19253 -13881 -9657 -19772 -2792 13606 11109 -13348 -1609 -4130 8926 16567 -3273 5858 20853 -3586 -20102 -9128 7717 -15194 961 3665 -16507 -4716 8509 -17671 110 -17364 -601 -20941 -16594 1621 -4047 4524 3323 -19013 -3345 2258 -10886 16520 -14046 -14134 20913 4155 13198 20291 -20906 14571 -1010 17587 -12797 -12223 9078 -7829 4535 -3887 5275 -16830"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 4 5 2 3 1 6 | grep "ERROR SUMMARY"

make fclean
cd ..
sh git.sh $*
cd push_swap