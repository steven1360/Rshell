#!/bin/sh

INPUTS=("echo terry && echo steven || ls"
	"ls; ls; echo \"testing\" && ls"
	"echo this is an echo || invalid"
	"pwd && echo terry || bro; ls -a"
	"pwd; pwd && pwd && echa; ls"
	"echo test && cat \"multiple_commands_tests.sh\""
	)


./command_test ${INPUTS[0]}
./command_test ${INPUTS[1]}
./command_test ${INPUTS[2]}
./command_test ${INPUTS[3]}
./command_test ${INPUTS[4]}
./command_test ${INPUTS[5]}
