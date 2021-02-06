#!/bin/sh
mkdir bin 2>/dev/null
cp ../cutils/arg.* ./ 2>/dev/null
gcc -ggdb -o ./bin/rkg main.c arg.c -O3 -Wall 
