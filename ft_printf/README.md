# ft_printf
- The prototype of ft_printf should be int ft_printf(const char *, ...);
- You have to recode the libc’s printf function
- It must not do the buffer management like the real printf
- It will manage the following conversions: cspdiuxX%
- It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions
- It will be compared with the real printf
- You must use the command ar to create your librairy, using the command libtool
is forbidden.

<br>

# How to build
Build the files.
```
make
```
Rebuild
```
make re
```
Clean .o files
```
make clean
```
Clean all files
```
make fclean
```

# How to run
main.c is your program. Please write #include "ft_printf.h" in your main.c.
```
gcc main.c -L. -lftprintf
```
Run the program.
```
./a.out
```