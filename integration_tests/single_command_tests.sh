#!/bin/sh

INPUTS=("echo truongformer" "ls" "pwd" "git status" "mkdir newDirectory" "ls -a" "cat -n testDirectory" "ls" "exit invalid")

for input in "${INPUTS[@]}"
do
        ./test "${input}"
done
