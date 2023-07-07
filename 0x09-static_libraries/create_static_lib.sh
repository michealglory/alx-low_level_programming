#!/bin/bash

# Find all .c files in the current directory
c_files=$(find . -maxdepth 1 -type f -name '*.c')

# Compile each .c file into an object file
object_files=""
for file in $c_files; do
    object_file="${file%.c}.o"
    gcc -c "$file" -o "$object_file"
    object_files+=" $object_file"
done

# Create the static library from the object files
ar rcs liball.a $object_files

# Clean up object files
rm -f $object_files
