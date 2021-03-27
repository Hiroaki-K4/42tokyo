#!/bin/bash

gcc -Wall -Werror -Wextra inter.c -o union
cd ../../
sh git.sh
cd exam_02/union