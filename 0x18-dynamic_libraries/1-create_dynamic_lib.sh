#!/bin/bash

# Compile all .c files into object files
gcc -c -Wall -Werror -fpic *.c

# Create the dynamic library
gcc -shared -o liball.so *.o

# Clean up object files
rm -f *.o
