#!/bin/sh

INPUTS=("[ -e integration_test.cpp ]"
		"[ -f test_literal_tests.sh ]"
		"[-d dir ]"
		"[ test -e test/file/path && echo “path exists ]"
		"[ echo test && test int_test ]"
		"[ test int_test || echo test ]"
		"( [ -f int_test ] && [ -e integration_test.cpp ]) || (echo testin && [something] )"
		"[ idk ]"
		"[ -a integration_test.cpp ]"
		"[ integration_test.cpp ]"
)

for input in "${INPUTS[@]}"
do
        ./int_test "${input}"
done
