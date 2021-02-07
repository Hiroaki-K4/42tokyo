#!/bin/bash

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c -lbsd 
./a.out