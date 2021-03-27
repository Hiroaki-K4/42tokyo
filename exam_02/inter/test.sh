#!/bin/bash

gcc -Wall -Werror -Wextra inter.c -o inter
cd ../../
sh git.sh
cd exam_02/inter