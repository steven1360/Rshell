#!/bin/sh

INPUTS=("echo terry exit" "echo terry && exit;" "echo test && echo one; pwd && exit && ls" 
	"exit; echo output nothing" "ls; exit; echo yea")


for input in "${INPUTS[@]}"
do
    ./test "${input}"
done
