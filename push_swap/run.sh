#!/bin/bash

make re
# ./push_swap 1 2 3 4 5
# ./push_swap 4 5 2 3 1 6
# ARG="4 5 2 3 1 6"; ./push_swap $ARG | wc -l
# ARG="4 5 2 3 1 6"; ./push_swap $ARG | ./checker $ARG
# ./push_swap 4 5 2 3 8 1 6 7
# ./push_swap 16 3 11 2 15 8 4 20 18 5 13 19 1 9 17 12 6 7 10 14
# ./push_swap 16 3 11 2 15 8

echo "~~~100~~~"
# ./push_swap -3185 -7805 -3020 -9648 -1496 -7263 -5934 4705 -1872 9175 -768 -2712 -9031 5410 -3246 3249 -4425 6418 788 4693 6550 -7941 -9657 -4446 3700 5360 -4742 -5580 -8819 -6317 -9272 -2003 -401 -2292 2070 8104 4167 9857 6529 -7706 -7250 -518 -418 -6279 -1388 -9944 -9310 7908 -9806 1479 2600 6745 7259 6664 -3981 958 5744 4998 5379 6926 8681 6107 -1357 -1720 -2465 -5567 104 -8299 -5711 353 -2283 761 -6445 7299 8203 5888 -8924 8894 3795 -8730 4093 115 -8265 5072 -3221 -2246 -250 -7478 -7249 -4872 -6832 -8568 -5045 1811 3433 2491 9965 -6464 7913 -2026
ARG="-3185 -7805 -3020 -9648 -1496 -7263 -5934 4705 -1872 9175 -768 -2712 -9031 5410 -3246 3249 -4425 6418 788 4693 6550 -7941 -9657 -4446 3700 5360 -4742 -5580 -8819 -6317 -9272 -2003 -401 -2292 2070 8104 4167 9857 6529 -7706 -7250 -518 -418 -6279 -1388 -9944 -9310 7908 -9806 1479 2600 6745 7259 6664 -3981 958 5744 4998 5379 6926 8681 6107 -1357 -1720 -2465 -5567 104 -8299 -5711 353 -2283 761 -6445 7299 8203 5888 -8924 8894 3795 -8730 4093 115 -8265 5072 -3221 -2246 -250 -7478 -7249 -4872 -6832 -8568 -5045 1811 3433 2491 9965 -6464 7913 -2026"; ./push_swap $ARG | wc -l
ARG="-3185 -7805 -3020 -9648 -1496 -7263 -5934 4705 -1872 9175 -768 -2712 -9031 5410 -3246 3249 -4425 6418 788 4693 6550 -7941 -9657 -4446 3700 5360 -4742 -5580 -8819 -6317 -9272 -2003 -401 -2292 2070 8104 4167 9857 6529 -7706 -7250 -518 -418 -6279 -1388 -9944 -9310 7908 -9806 1479 2600 6745 7259 6664 -3981 958 5744 4998 5379 6926 8681 6107 -1357 -1720 -2465 -5567 104 -8299 -5711 353 -2283 761 -6445 7299 8203 5888 -8924 8894 3795 -8730 4093 115 -8265 5072 -3221 -2246 -250 -7478 -7249 -4872 -6832 -8568 -5045 1811 3433 2491 9965 -6464 7913 -2026"; ./push_swap $ARG | ./checker $ARG
# ./push_swap 139943846 -67606124 -109806271 -143063745 -63912341 -176013237 -62062359 46548325 -11867473 -137341493 130964653 13555827 -133793489 -48925838 -126604493 -107906935 -139162979 78494686 -42687691 -2718334 -173505997 -192516527 -66635212 119404611 126868133 23206233 176281649 -48266200 183128862 88980152 -184075866 108324340 -193374337 -79133772 180008959 -42538316 -40398648 -96801768 -210738356 162482243 -19394896 134974658 -38710298 61559976 -128699545 49433573 168401405 -53114160 -86820109 -89034650 158915871 -45577742 -66802816 -122467709 -140921498 -154683050 115486889 -179388217 11799111 83867383 124340300 42471610 -22556645 145714327 178086199 -57296051 -111572354 -77060814 60650543 -107562349 -129326939 -173492721 -187336055 46711125 102815619 -101287236 -118603670 56468657 60346966 9324583 182182371 4514469 178495205 -99368813 96795121 -177174661 -39303502 -2466358 -141814513 187243974 -133347343 197274151 14967216 58844376 128240110 -21694953 -213200042 -198080611 115992597 62198865
ARG="139943846 -67606124 -109806271 -143063745 -63912341 -176013237 -62062359 46548325 -11867473 -137341493 130964653 13555827 -133793489 -48925838 -126604493 -107906935 -139162979 78494686 -42687691 -2718334 -173505997 -192516527 -66635212 119404611 126868133 23206233 176281649 -48266200 183128862 88980152 -184075866 108324340 -193374337 -79133772 180008959 -42538316 -40398648 -96801768 -210738356 162482243 -19394896 134974658 -38710298 61559976 -128699545 49433573 168401405 -53114160 -86820109 -89034650 158915871 -45577742 -66802816 -122467709 -140921498 -154683050 115486889 -179388217 11799111 83867383 124340300 42471610 -22556645 145714327 178086199 -57296051 -111572354 -77060814 60650543 -107562349 -129326939 -173492721 -187336055 46711125 102815619 -101287236 -118603670 56468657 60346966 9324583 182182371 4514469 178495205 -99368813 96795121 -177174661 -39303502 -2466358 -141814513 187243974 -133347343 197274151 14967216 58844376 128240110 -21694953 -213200042 -198080611 115992597 62198865"; ./push_swap $ARG | wc -l
ARG="139943846 -67606124 -109806271 -143063745 -63912341 -176013237 -62062359 46548325 -11867473 -137341493 130964653 13555827 -133793489 -48925838 -126604493 -107906935 -139162979 78494686 -42687691 -2718334 -173505997 -192516527 -66635212 119404611 126868133 23206233 176281649 -48266200 183128862 88980152 -184075866 108324340 -193374337 -79133772 180008959 -42538316 -40398648 -96801768 -210738356 162482243 -19394896 134974658 -38710298 61559976 -128699545 49433573 168401405 -53114160 -86820109 -89034650 158915871 -45577742 -66802816 -122467709 -140921498 -154683050 115486889 -179388217 11799111 83867383 124340300 42471610 -22556645 145714327 178086199 -57296051 -111572354 -77060814 60650543 -107562349 -129326939 -173492721 -187336055 46711125 102815619 -101287236 -118603670 56468657 60346966 9324583 182182371 4514469 178495205 -99368813 96795121 -177174661 -39303502 -2466358 -141814513 187243974 -133347343 197274151 14967216 58844376 128240110 -21694953 -213200042 -198080611 115992597 62198865"; ./push_swap $ARG | ./checker $ARG
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 4 5 2 3 1 6 | grep "ERROR SUMMARY"


# 150
# ./push_swap -101560338 6348114 -134830394 -77507678 -102349654 -167969506 -120674824 -199780868 -29682664 131640096 27702648 35158282 -102310357 156007846 118487990 -133321343 -87306564 -183361866 119799453 116246760 -75282234 -150552027 -93658617 171454884 -126516673 78077281 -166247107 7284153 69756529 -153520093 45379119 182944555 67576382 125297089 -109311488 179975092 172075944 -15237951 194942585 -72355088 -98346223 7896868 177551559 14091781 -50843654 81291181 95518803 76598144 112677679 569888 -21903461 -177352923 64766226 99186283 208850325 152997917 -37484801 -172145149 -54466298 -182476637 -110916878 205661185 -214280449 171407868 116209906 -108843576 136634592 73537482 90666838 116828812 -213565970 207068979 -90022687 178733950 6412393 73882023 45276766 -112817172 -64268198 -56793923 102501080 128576703 -19398481 -47481059 13014621 -25296524 -109231510 190278185 17306691 51050553 -206946820 121138174 41963370 -206478905 77797677 -56575092 -100574116 -316099 -197785977 204841083 -98235651 -196603583 197161694 26490023 196878728 -11174278 -114376319 27407126 90756914 36103845 185361564 -21490370 -50067817 -48785285 145776932 177695165 140666556 -178202945 153224982 -56775121 87595972 161026524 -150385311 -85189025 169295983 142160727 72984247 -146026501 -72903736 89946634 -155933786 43608974 108091412 -173520456 -144649368 90221775 30053627 -44277326 -97119467 -93937826 206574883 -126506267 99320168 -58241302 39456809 30348732 -95294501 -34625000 66894148 -156817887

# echo "~~~200~~~"
# ./push_swap 184555995 -7507697 149749413 -41834850 97096076 120025885 22051413 -67529666 211953826 -119558934 44261516 -92263448 -159278780 164049683 168532406 -98582853 28214617 -101090862 137969476 -203912537 -98336120 90718917 77859714 -38564296 -157433540 127054118 100822281 16617714 14002951 -166311539 60287561 -16189422 40929128 -4711391 156724093 -76723161 -99433874 -35972862 70495535 -102228416 59216569 -99991314 20256501 114686153 -150689998 -25959461 -198645068 92272980 87698038 154072770 103108804 204110282 30043322 -33779850 -49202379 87358144 -121474097 -163128465 -110772507 107277215 -114691640 164263418 -123660571 140985850 -55196341 -181684846 -150485679 60118150 -2909344 134758220 172638095 -158441140 -179981461 -21853772 170993375 -115923095 166935131 187096668 191098249 39884801 126421073 79458688 29246719 -58283972 -169069529 194792701 -185674196 -75795262 -183084132 -81698339 -183266411 -83027407 -132183288 -92178621 -156789925 27368732 -59115106 -92527240 -127261486 152723914 -172517384 -169371755 209031136 -137750481 23522837 165276143 -38925215 -24290399 137624446 -62575334 -199153966 49297152 -197865014 44841117 205761541 -152186179 24885454 -194661020 -13233076 56549686 -61610998 18248874 188270640 20954075 140818617 -183267650 -166425557 -133044857 -61046525 -78938679 -195069311 -18815548 -33562073 -200786543 58182332 204709126 179237964 -195491248 -34329641 102114043 -43318218 -18735243 -63337173 -26434868 -188642490 -72324000 36127318 50991325 -52236656 -191854126 -107207357 100900707 41143112 -133685084 -92893582 -32786639 -102204370 -44570778 48916868 51497466 91238907 68595918 -182066450 -157071533 82557740 90864246 -167110772 47047339 110121359 13307948 -65586986 -147945227 209321069 85824205 40368267 -194069789 -201248160 -138252783 71669900 -38736455 -115358545 179210905 -152584112 140532928 -169222544 -30729333 -107002079 -56678553 139448253 156663150 209567275 15938792 10510703 -187247540 73615623 -121679922 118365068 121253212 140115779 13738059
# ARG="184555995 -7507697 149749413 -41834850 97096076 120025885 22051413 -67529666 211953826 -119558934 44261516 -92263448 -159278780 164049683 168532406 -98582853 28214617 -101090862 137969476 -203912537 -98336120 90718917 77859714 -38564296 -157433540 127054118 100822281 16617714 14002951 -166311539 60287561 -16189422 40929128 -4711391 156724093 -76723161 -99433874 -35972862 70495535 -102228416 59216569 -99991314 20256501 114686153 -150689998 -25959461 -198645068 92272980 87698038 154072770 103108804 204110282 30043322 -33779850 -49202379 87358144 -121474097 -163128465 -110772507 107277215 -114691640 164263418 -123660571 140985850 -55196341 -181684846 -150485679 60118150 -2909344 134758220 172638095 -158441140 -179981461 -21853772 170993375 -115923095 166935131 187096668 191098249 39884801 126421073 79458688 29246719 -58283972 -169069529 194792701 -185674196 -75795262 -183084132 -81698339 -183266411 -83027407 -132183288 -92178621 -156789925 27368732 -59115106 -92527240 -127261486 152723914 -172517384 -169371755 209031136 -137750481 23522837 165276143 -38925215 -24290399 137624446 -62575334 -199153966 49297152 -197865014 44841117 205761541 -152186179 24885454 -194661020 -13233076 56549686 -61610998 18248874 188270640 20954075 140818617 -183267650 -166425557 -133044857 -61046525 -78938679 -195069311 -18815548 -33562073 -200786543 58182332 204709126 179237964 -195491248 -34329641 102114043 -43318218 -18735243 -63337173 -26434868 -188642490 -72324000 36127318 50991325 -52236656 -191854126 -107207357 100900707 41143112 -133685084 -92893582 -32786639 -102204370 -44570778 48916868 51497466 91238907 68595918 -182066450 -157071533 82557740 90864246 -167110772 47047339 110121359 13307948 -65586986 -147945227 209321069 85824205 40368267 -194069789 -201248160 -138252783 71669900 -38736455 -115358545 179210905 -152584112 140532928 -169222544 -30729333 -107002079 -56678553 139448253 156663150 209567275 15938792 10510703 -187247540 73615623 -121679922 118365068 121253212 140115779 13738059"; ./push_swap $ARG | wc -l
# ./push_swap -192086952 163061507 109433532 85005557 81701711 97005185 -181876022 -80523025 -4083009 -98522275 -121372504 50026859 138231885 214548314 113100255 -195115595 -67557122 -101121158 86169273 142906464 61219303 65026270 127584461 -146868860 83149730 -196588907 66315910 -170500525 -72213500 103788067 173410147 -49552090 52101210 68095312 -179294898 -80945444 -49647868 -146422555 53279892 161017488 -30196469 146655749 -3704021 -106712949 146455699 -105352133 -87080182 -135849791 8275073 213837455 -207691692 -145253992 64115361 134641131 -77374488 -67483277 152800588 203689784 -23235441 -134161280 92729486 -64573662 31034994 -69917672 -211226718 66488461 63885248 -46126221 134814267 -97583228 -99857101 -110130567 -165675843 111187239 -2095151 195528220 -208913262 125573028 -155069939 14110173 124662118 -148013266 83604545 -25970889 201376229 -208518310 121294195 139428449 209919838 -116689611 -209481196 87900956 33485089 36302163 -196765083 37006735 -111957744 81868529 205628878 -191891845 199033663 -108976591 -87274048 -181390545 -212537719 125379162 -200610693 -206702620 36203825 -140932268 22155917 -53882424 -74197173 -108987902 134895051 -87569312 -102757851 41440882 -162889231 -107586381 139499632 -157622065 195062939 -41763644 93428462 213046220 209991456 196219079 80166382 200871966 -210421131 64451677 -122852992 -82946818 97809496 -120642350 -172316020 111947164 -112596606 78636169 185763260 124307676 -189994623 -103182280 -199428594 159648793 23996772 -87438081 -13658693 75855903 19723902 -88907429 132982202 38473 84077289 11662296 -1663674 79320377 -6866990 -136245660 65443975 -2539760 142954381 157339347 129261786 26015509 -178051371 171694130 -76785695 -75899612 35581932 -105770803 -166340304 60335673 5795281 -151020534 5236098 -184956314 -23710254 206325769 105647953 210762009 -97330027 23881790 -3947886 201495626 -179204279 209136801 66067638 28677092 -141857227 -83236752 -188611033 -213651214 -140645772 155399114 27112659 -103948779 112344880 165075328

# 500
echo "~~~500~~~"
# ./push_swap 70482278 203919796 -130122987 10602650 159245606 27166265 -133119498 48717895 190710081 -160250121 205169705 72522538 -39726440 178381046 -92132870 -197920408 -205393058 -203792366 -172704202 -118482450 -168099463 -28766038 57143989 -165645739 -9516161 167373887 -38426849 64495071 -179423530 173311090 45088882 105807109 162482522 129714259 -98338606 106979760 -57867841 -16709739 -59050713 -81906128 37788501 -68629375 205364774 212810425 -104996697 -101516464 -199858351 -95641391 -90560465 -157814189 624520 -43911564 28168135 -156979855 5191059 -196096394 -204354336 181512574 83147038 -169029504 140075300 -86512445 151525969 87809454 -171546554 -161561001 -19959154 -14666031 36477621 135738497 118176205 -140482246 -147639246 108792611 -142420189 -37887578 -207472220 -127530176 81219392 -83284324 -70596004 -132904452 87552476 172320492 -75135946 -122004833 190972462 -64741918 -155240623 59371133 -19023058 199583038 187607052 -82245456 72644124 -198687866 -29058093 -162063395 1394464 -207328840 188423463 -95177698 -133062722 -173964147 -201133455 -60734547 2896636 -193857311 26483638 -130632337 -62393271 170635998 -48788425 -189589162 128208126 90823993 -96845631 104432220 -188666292 -37337893 -50945012 7059011 -52503220 -78086327 139561919 -194607461 -62025829 -104244542 -141922495 154116996 -96825018 -168247396 -155809067 -15139379 -127463182 -142194160 138874438 90181818 -121303107 -49390289 174297842 31051987 -93502658 -89238950 56211186 -180042900 -213163322 174113919 139137684 -187081253 -77972338 -126555695 34726123 84272803 10106342 -40460326 104413707 162828874 70043497 177239573 102197505 187966840 -205756191 161136800 -41920903 -118471009 -195805725 -117794833 186459170 -102360471 47563240 146008648 143439877 168808946 -157978670 -15097302 203514410 -156393628 -55731750 127903726 -128726519 81044273 -213400337 120747968 -49431289 11454369 -134460723 -159765950 -40465125 150331135 -197274741 -153015987 123549611 -188282568 -206627555 -133119660 -92005215 -187684919 -36166129 -120294410 -75297026 -203351257 -189034130 -146605513 180206053 -132264436 53045549 168972095 -73909702 212062160 82127454 12112143 78358068 83475481 -81888257 -185821585 -119818517 -1600616 -130839174 54464719 -66017848 -113365551 116197096 -157216602 -86899757 124317905 -75587898 35843392 151381350 102994334 130297343 -138664043 114391442 156011575 -70521192 79849127 -191001229 197272718 34072855 -50162567 194586514 -98548056 176697937 58196217 199675786 -119938685 87122993 -134891099 93209061 171032184 134321985 -187557152 -157081735 35770716 -130025393 -29233131 -54659746 9135070 -208138107 -118026764 -102618961 136907601 -41942443 -202975887 78170811 102284729 91621605 101917943 84809080 -89053905 -162992991 64647229 27146400 -201043419 -91904922 12073821 -106233742 209966433 91931087 201723680 166250249 11504704 -200581840 -205579854 -167472945 -115858869 -20064620 -7384330 108024565 -13454363 89337271 -209342764 -91295130 -167353537 -197570289 201624045 149679554 108799680 88793621 19740269 -195002593 140548994 -130360870 46892168 154253939 -7517431 -155782379 -166728171 -12299363 150897072 -179752856 -60797479 -52346592 -165586332 -51628971 -5071172 -66696837 143054773 202292859 -173420640 -85147958 76881765 -168015042 38305277 124276590 -150836967 25180954 59207776 172711077 -100773790 -135800320 192456845 -174973161 -51412829 24600648 194029140 155818104 83566633 -187447396 -71229623 19715338 -152451887 82721259 182117110 -103289858 -183656077 -37702430 44761667 174147057 -50157935 86089391 -125749265 -188024538 132822713 127304376 151000413 196734107 -62263035 -4540176 154696816 51711540 74407865 132405296 91486740 -191753329 -57742424 70767515 178813140 -188924158 98068484 -107164851 45539544 160364958 190304769 12908286 -157673268 -208099675 189954218 101836763 180795746 -74952085 -26822210 -159701887 -48228259 -108747865 182350853 -111976213 -126762125 -94660549 98231975 -186813674 171799352 -42108524 160339987 48537727 -19113489 -112150805 -95443125 -55048717 -86326599 -212123009 52534793 173961306 162990313 28091198 -27878775 -209431320 34739887 -52672922 107153808 787265 87123357 -134416770 55833743 -175853270 -28416274 23436228 -73081119 59569965 143524043 -189597511 87504656 100575030 -16957671 33096275 -65635610 178677201 135693831 53669629 -91119883 -165381135 56294984 176163274 -206168194 4536932 -10493896 -19298605 9853973 -190502377 142776834 -97740587 25033253 15151823 -17408996 -133881372 54046915 168923092 104303220 195714157 13744692 33078899 -208631719 -113499020 -81094439 -10841029 134345616 68018315 -46912192 55291080 -93060421 76716289 104658309 177982927 38131195 113238479 -32228509 -187111065 -120808493 192373826 -162865081 -192780027 -120115126 76916536 37120161 77224240 157783528 -123581292 31398967 47338381 -142615500 -169604709 -134331088 -136498854 -68355367 -677163 67408481 -148758119 -147407212 -194252079 121281325 -25719272 97212571 11191269 -62484709 -79404598 -90318619 120035143 -51767302 3621252 97660604
ARG="70482278 203919796 -130122987 10602650 159245606 27166265 -133119498 48717895 190710081 -160250121 205169705 72522538 -39726440 178381046 -92132870 -197920408 -205393058 -203792366 -172704202 -118482450 -168099463 -28766038 57143989 -165645739 -9516161 167373887 -38426849 64495071 -179423530 173311090 45088882 105807109 162482522 129714259 -98338606 106979760 -57867841 -16709739 -59050713 -81906128 37788501 -68629375 205364774 212810425 -104996697 -101516464 -199858351 -95641391 -90560465 -157814189 624520 -43911564 28168135 -156979855 5191059 -196096394 -204354336 181512574 83147038 -169029504 140075300 -86512445 151525969 87809454 -171546554 -161561001 -19959154 -14666031 36477621 135738497 118176205 -140482246 -147639246 108792611 -142420189 -37887578 -207472220 -127530176 81219392 -83284324 -70596004 -132904452 87552476 172320492 -75135946 -122004833 190972462 -64741918 -155240623 59371133 -19023058 199583038 187607052 -82245456 72644124 -198687866 -29058093 -162063395 1394464 -207328840 188423463 -95177698 -133062722 -173964147 -201133455 -60734547 2896636 -193857311 26483638 -130632337 -62393271 170635998 -48788425 -189589162 128208126 90823993 -96845631 104432220 -188666292 -37337893 -50945012 7059011 -52503220 -78086327 139561919 -194607461 -62025829 -104244542 -141922495 154116996 -96825018 -168247396 -155809067 -15139379 -127463182 -142194160 138874438 90181818 -121303107 -49390289 174297842 31051987 -93502658 -89238950 56211186 -180042900 -213163322 174113919 139137684 -187081253 -77972338 -126555695 34726123 84272803 10106342 -40460326 104413707 162828874 70043497 177239573 102197505 187966840 -205756191 161136800 -41920903 -118471009 -195805725 -117794833 186459170 -102360471 47563240 146008648 143439877 168808946 -157978670 -15097302 203514410 -156393628 -55731750 127903726 -128726519 81044273 -213400337 120747968 -49431289 11454369 -134460723 -159765950 -40465125 150331135 -197274741 -153015987 123549611 -188282568 -206627555 -133119660 -92005215 -187684919 -36166129 -120294410 -75297026 -203351257 -189034130 -146605513 180206053 -132264436 53045549 168972095 -73909702 212062160 82127454 12112143 78358068 83475481 -81888257 -185821585 -119818517 -1600616 -130839174 54464719 -66017848 -113365551 116197096 -157216602 -86899757 124317905 -75587898 35843392 151381350 102994334 130297343 -138664043 114391442 156011575 -70521192 79849127 -191001229 197272718 34072855 -50162567 194586514 -98548056 176697937 58196217 199675786 -119938685 87122993 -134891099 93209061 171032184 134321985 -187557152 -157081735 35770716 -130025393 -29233131 -54659746 9135070 -208138107 -118026764 -102618961 136907601 -41942443 -202975887 78170811 102284729 91621605 101917943 84809080 -89053905 -162992991 64647229 27146400 -201043419 -91904922 12073821 -106233742 209966433 91931087 201723680 166250249 11504704 -200581840 -205579854 -167472945 -115858869 -20064620 -7384330 108024565 -13454363 89337271 -209342764 -91295130 -167353537 -197570289 201624045 149679554 108799680 88793621 19740269 -195002593 140548994 -130360870 46892168 154253939 -7517431 -155782379 -166728171 -12299363 150897072 -179752856 -60797479 -52346592 -165586332 -51628971 -5071172 -66696837 143054773 202292859 -173420640 -85147958 76881765 -168015042 38305277 124276590 -150836967 25180954 59207776 172711077 -100773790 -135800320 192456845 -174973161 -51412829 24600648 194029140 155818104 83566633 -187447396 -71229623 19715338 -152451887 82721259 182117110 -103289858 -183656077 -37702430 44761667 174147057 -50157935 86089391 -125749265 -188024538 132822713 127304376 151000413 196734107 -62263035 -4540176 154696816 51711540 74407865 132405296 91486740 -191753329 -57742424 70767515 178813140 -188924158 98068484 -107164851 45539544 160364958 190304769 12908286 -157673268 -208099675 189954218 101836763 180795746 -74952085 -26822210 -159701887 -48228259 -108747865 182350853 -111976213 -126762125 -94660549 98231975 -186813674 171799352 -42108524 160339987 48537727 -19113489 -112150805 -95443125 -55048717 -86326599 -212123009 52534793 173961306 162990313 28091198 -27878775 -209431320 34739887 -52672922 107153808 787265 87123357 -134416770 55833743 -175853270 -28416274 23436228 -73081119 59569965 143524043 -189597511 87504656 100575030 -16957671 33096275 -65635610 178677201 135693831 53669629 -91119883 -165381135 56294984 176163274 -206168194 4536932 -10493896 -19298605 9853973 -190502377 142776834 -97740587 25033253 15151823 -17408996 -133881372 54046915 168923092 104303220 195714157 13744692 33078899 -208631719 -113499020 -81094439 -10841029 134345616 68018315 -46912192 55291080 -93060421 76716289 104658309 177982927 38131195 113238479 -32228509 -187111065 -120808493 192373826 -162865081 -192780027 -120115126 76916536 37120161 77224240 157783528 -123581292 31398967 47338381 -142615500 -169604709 -134331088 -136498854 -68355367 -677163 67408481 -148758119 -147407212 -194252079 121281325 -25719272 97212571 11191269 -62484709 -79404598 -90318619 120035143 -51767302 3621252 97660604"; ./push_swap $ARG | wc -l
ARG="70482278 203919796 -130122987 10602650 159245606 27166265 -133119498 48717895 190710081 -160250121 205169705 72522538 -39726440 178381046 -92132870 -197920408 -205393058 -203792366 -172704202 -118482450 -168099463 -28766038 57143989 -165645739 -9516161 167373887 -38426849 64495071 -179423530 173311090 45088882 105807109 162482522 129714259 -98338606 106979760 -57867841 -16709739 -59050713 -81906128 37788501 -68629375 205364774 212810425 -104996697 -101516464 -199858351 -95641391 -90560465 -157814189 624520 -43911564 28168135 -156979855 5191059 -196096394 -204354336 181512574 83147038 -169029504 140075300 -86512445 151525969 87809454 -171546554 -161561001 -19959154 -14666031 36477621 135738497 118176205 -140482246 -147639246 108792611 -142420189 -37887578 -207472220 -127530176 81219392 -83284324 -70596004 -132904452 87552476 172320492 -75135946 -122004833 190972462 -64741918 -155240623 59371133 -19023058 199583038 187607052 -82245456 72644124 -198687866 -29058093 -162063395 1394464 -207328840 188423463 -95177698 -133062722 -173964147 -201133455 -60734547 2896636 -193857311 26483638 -130632337 -62393271 170635998 -48788425 -189589162 128208126 90823993 -96845631 104432220 -188666292 -37337893 -50945012 7059011 -52503220 -78086327 139561919 -194607461 -62025829 -104244542 -141922495 154116996 -96825018 -168247396 -155809067 -15139379 -127463182 -142194160 138874438 90181818 -121303107 -49390289 174297842 31051987 -93502658 -89238950 56211186 -180042900 -213163322 174113919 139137684 -187081253 -77972338 -126555695 34726123 84272803 10106342 -40460326 104413707 162828874 70043497 177239573 102197505 187966840 -205756191 161136800 -41920903 -118471009 -195805725 -117794833 186459170 -102360471 47563240 146008648 143439877 168808946 -157978670 -15097302 203514410 -156393628 -55731750 127903726 -128726519 81044273 -213400337 120747968 -49431289 11454369 -134460723 -159765950 -40465125 150331135 -197274741 -153015987 123549611 -188282568 -206627555 -133119660 -92005215 -187684919 -36166129 -120294410 -75297026 -203351257 -189034130 -146605513 180206053 -132264436 53045549 168972095 -73909702 212062160 82127454 12112143 78358068 83475481 -81888257 -185821585 -119818517 -1600616 -130839174 54464719 -66017848 -113365551 116197096 -157216602 -86899757 124317905 -75587898 35843392 151381350 102994334 130297343 -138664043 114391442 156011575 -70521192 79849127 -191001229 197272718 34072855 -50162567 194586514 -98548056 176697937 58196217 199675786 -119938685 87122993 -134891099 93209061 171032184 134321985 -187557152 -157081735 35770716 -130025393 -29233131 -54659746 9135070 -208138107 -118026764 -102618961 136907601 -41942443 -202975887 78170811 102284729 91621605 101917943 84809080 -89053905 -162992991 64647229 27146400 -201043419 -91904922 12073821 -106233742 209966433 91931087 201723680 166250249 11504704 -200581840 -205579854 -167472945 -115858869 -20064620 -7384330 108024565 -13454363 89337271 -209342764 -91295130 -167353537 -197570289 201624045 149679554 108799680 88793621 19740269 -195002593 140548994 -130360870 46892168 154253939 -7517431 -155782379 -166728171 -12299363 150897072 -179752856 -60797479 -52346592 -165586332 -51628971 -5071172 -66696837 143054773 202292859 -173420640 -85147958 76881765 -168015042 38305277 124276590 -150836967 25180954 59207776 172711077 -100773790 -135800320 192456845 -174973161 -51412829 24600648 194029140 155818104 83566633 -187447396 -71229623 19715338 -152451887 82721259 182117110 -103289858 -183656077 -37702430 44761667 174147057 -50157935 86089391 -125749265 -188024538 132822713 127304376 151000413 196734107 -62263035 -4540176 154696816 51711540 74407865 132405296 91486740 -191753329 -57742424 70767515 178813140 -188924158 98068484 -107164851 45539544 160364958 190304769 12908286 -157673268 -208099675 189954218 101836763 180795746 -74952085 -26822210 -159701887 -48228259 -108747865 182350853 -111976213 -126762125 -94660549 98231975 -186813674 171799352 -42108524 160339987 48537727 -19113489 -112150805 -95443125 -55048717 -86326599 -212123009 52534793 173961306 162990313 28091198 -27878775 -209431320 34739887 -52672922 107153808 787265 87123357 -134416770 55833743 -175853270 -28416274 23436228 -73081119 59569965 143524043 -189597511 87504656 100575030 -16957671 33096275 -65635610 178677201 135693831 53669629 -91119883 -165381135 56294984 176163274 -206168194 4536932 -10493896 -19298605 9853973 -190502377 142776834 -97740587 25033253 15151823 -17408996 -133881372 54046915 168923092 104303220 195714157 13744692 33078899 -208631719 -113499020 -81094439 -10841029 134345616 68018315 -46912192 55291080 -93060421 76716289 104658309 177982927 38131195 113238479 -32228509 -187111065 -120808493 192373826 -162865081 -192780027 -120115126 76916536 37120161 77224240 157783528 -123581292 31398967 47338381 -142615500 -169604709 -134331088 -136498854 -68355367 -677163 67408481 -148758119 -147407212 -194252079 121281325 -25719272 97212571 11191269 -62484709 -79404598 -90318619 120035143 -51767302 3621252 97660604"; ./push_swap $ARG | ./checker $ARG
./push_swap 8407273 -3130154 7271774 7583684 10793166 -21288771 18077092 15997323 -7982834 -1095617 -4453282 -4794348 -20743387 -1372494 6313770 5876968 -13108677 7560200 -15990318 13671047 -738083 -11666059 15741265 -4783683 -17814367 -20670382 2595020 -3351559 -2746085 -4845873 -16419121 15598597 -19048934 12639401 4916928 -18862869 9241656 -560586 -5370867 -13328796 16460968 11309624 -12597347 -3407214 -11537707 15191261 -19005081 -3171546 1276625 -13520563 -10975336 -20936293 -3711786 -16708905 -4245140 -51315 -15904451 19824716 18071964 2824301 -6495992 -19821994 -3051937 -4070090 14292243 -19609843 -1458122 2059064 1304407 14645849 10205107 -3709459 4480636 19082596 14358165 14417766 12799023 16827920 -10228615 -18167477 270886 -404425 5036817 10369052 21019099 10607204 8718931 17616226 -8043330 -19251895 19269071 10379570 -1847149 12086477 12244563 18169567 -7329293 -7925865 11340580 -18599023 9839514 -5653621 -20991262 2722842 -12710690 13282597 -1924072 -1464468 -15591427 1383289 20281254 -977235 -20495973 3843236 -12083020 -20951711 -7024395 18110750 18139354 6407112 20333691 15933588 -4688153 -2988293 6545230 -13918427 -6293562 20690773 -369454 -16427819 -19383085 -12004776 -606604 -18899510 12192904 8157545 15857923 -11206003 -14781760 -21208340 11652122 -15975341 12630986 9342733 8681080 13154113 -19156499 5316993 9818630 8725451 4175849 4277381 -17437539 -20287281 -10652225 -9881128 -5106007 -11436287 11224255 -58990 -9344535 20694317 20809245 -6769207 11412386 7491953 -12386121 -21268453 14185031 -12119623 11858505 19684526 8644477 3014656 7552424 -4149280 -5306067 9870761 -20307122 -16962272 -2878624 5343563 8789946 1158675 6531118 19612559 12752384 -20049725 -13298563 2501804 1366123 -1168260 1721284 700533 13537369 -8341165 -13282349 -20323588 -8134782 -20572155 -10968373 -17751111 20587209 19150940 6738383 6664796 -6473175 -20042521 -4939277 -5305461 -15529954 13656937 -21436733 14734828 -6659225 6569222 12872552 -15381678 7994335 21048827 8594962 -12114377 -1594269 -11158589 10060993 -9531737 1975083 18253480 -8380487 15315139 19156164 2125979 19038864 18268536 -197918 4302411 3458498 14803746 5734728 19994057 -11976552 11679610 12176157 -11938448 4939603 -15957903 16105612 -3662680 -9864744 2625110 -4088689 20205056 11985571 15791880 -12428369 571727 -15214692 11021552 -2649627 -2120340 4861854 -4968298 -21469198 2425884 -8174597 -192278 -14746540 16758737 -6863369 12463026 15277959 2634916 2667802 5979281 12171306 -13867432 11496215 6802083 3944727 -19843364 -12047642 21330874 -21113145 21412765 15647917 -12066676 509656 -21041610 20429714 19334867 -1687114 -7108268 -1681476 -15232219 6191971 19601083 -8503921 1475872 -8737123 -17515732 -4721004 15372631 6626906 -20216559 6069102 14234313 12754494 -8603652 -3295797 14385966 823542 -3439758 14747659 761471 -9266676 -18793851 -20203708 -8833450 -19838974 20605995 10954273 5452596 -7977108 -12202040 11695213 19689699 -14075794 -18283543 -309264 -1338078 -14324438 16444569 -7440284 13777304 17702848 20103655 6536782 8982505 -9974832 -18233852 1893634 12323547 -198774 -4833542 -8389819 12009386 -2152557 -7118691 -18298900 -516694 -7987531 14130211 5510197 -19546666 16631117 3725059 -12147621 19822412 -18059039 7989137 -15976863 19860368 -20925982 19275280 16088379 20652511 4337225 3596047 -10797157 7578210 -15985154 -19948445 -14095399 656140 -6863426 19388826 19978422 7492719 -20384911 -2013109 20980026 15220136 2922794 5015386 17148308 -1920924 -12734390 -16474150 -3573348 -9318591 12989825 1924627 -10933060 13538682 -274930 -16319518 12716358 -17412539 8751367 -19555634 11640509 14241051 -18029243 19019946 -6577645 -3417833 16933935 -8074060 -17399949 18023862 11387669 -17894760 11769163 -7164372 8595464 7442635 12389541 17335913 12443323 -12658642 -13457515 3958314 10740821 -2915738 -3977839 -11008945 2239582 -12736318 -6946646 -10483887 -10817113 -16780974 -17717671 -7371520 -19235865 -2820480 10685486 19172909 10580298 14760373 15721934 493132 18340452 6016261 14803597 5461081 -8015939 5718303 1322157 -17047451 14534497 9339481 8385699 3800483 -15051094 -17066977 14266374 8663326 -8328456 19654277 2329267 -9461245 -19538230 -7222273 -883872 5643234 -9524201 -11778408 -1071227 -15277102 10189560 -4205610 12213997 3518322 -20219366 -17276779 -12238212 2577630 -12849393 -19178552 -9557726 17011144 6096768 -3133982 21419006 -1111693 -15945493 -8384287 6208037 -17766050 15419816 18221628 -15829444 10377564 -10475480 4761520 -5454036 1475157 14457948 14949573
make fclean
cd ..
sh git.sh $*
cd push_swap