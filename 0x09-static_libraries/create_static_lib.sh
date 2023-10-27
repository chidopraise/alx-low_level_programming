#!/bin/bash

# Compile all .c files in the current directory and create corresponding .o files
gcc -c *.c

# Create a static library liball.a from all .o files
ar -rc liball.a *.o

# Index the library for efficient linking
ranlib liball.a

# Clean up the .o files
rm -f *.o
