#!/bin/sh

INPUTS=("echo terry exit" "echo terry && exit;" "echo test && echo one; pwd && exit && ls" 
	"exit; echo output nothing" "ls; exit; echo yea" "echo test exit; exit  && && || ;")


for input in "${INPUTS[@]}"
do
    ./int_test "${input}"
done
