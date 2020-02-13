#!/bin/sh

INPUTS=("echo truongformer &&  echo junginator #our robot names" "#mkdir thisWontBeADirectory" "#git status" "ls #-a" "echo #hello world" "#pwid" "git branch && ls #-a" )

for input in "${INPUTS[@]}"
do
        ./test "${input}"
done

