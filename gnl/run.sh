#!/bin/bash

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=20000000000 get_next_line.c -lbsd 
./a.out