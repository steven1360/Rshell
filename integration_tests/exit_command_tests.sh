#!/bin/sh

INPUTS=("echo terry exit" "echo terry; exit;" )


./command_test "${INPUTS[0]}"
./command_test "${INPUTS[1]}"
#./command_test "${INPUTS[2]}"
#./command_test "${INPUTS[3]}"
#./command_test "${INPUTS[4]}"

