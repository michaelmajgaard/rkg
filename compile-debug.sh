#!/bin/sh
mkdir bin 2>/dev/null
cp ../cutils/arg.* ./
gcc -ggdb -o ./bin/main.o main.c arg.c $1
