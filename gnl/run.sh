#!/bin/bash

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c -lbsd 
./a.out