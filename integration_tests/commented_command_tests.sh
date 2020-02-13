#!/bin/sh

INPUTS=("echo truongformer &&  echo junginator #our robot names" "#mkdir thisWontBeADirectory" "#git status" "ls #-a" "echo #hello world" "#pwd")

for input in "${INPUTS[@]}"
do
        ./command_test ${input}
done

