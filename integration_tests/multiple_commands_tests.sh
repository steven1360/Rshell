#!/bin/sh

INPUTS=("echo terry && echo steven || ls"
	"ls; ls; echo \"testing\" && ls"
	"echo this is an echo || invalid"
	"pwd && echo terry || bro; ls -a"
	"pwdd; pwd && pwd && echa; ls"
	"echo test && cat \"multiple_commands_tests.sh\""
	)


for input in "${INPUTS[@]}"
do
        ./test "${input}"
done


