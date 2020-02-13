#!/bin/sh

INPUTS=("echo truongformer &&  echo junginator #our robot names" "#mkdir thisWontBeADirectory" "#git status" "ls #-a" "echo #hello world" "#pwid" "git branch && ls #-a" "ls; echo \"echo four && #echo two\" " 
	"echo \" #this is a comment \" && echo #idk"
)

for input in "${INPUTS[@]}"
do
        ./int_test "${input}"
done

