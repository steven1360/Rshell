#!/bin/sh

INPUTS=("echo truongformer" "ls" "pwd" "git status" "mkdir newDirectory" "ls -a" "cat -n testDirectory" "ls")

for input in "${INPUTS[@]}"
do
        ./command_test ${input}
done
