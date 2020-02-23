#!/bin/sh

INPUTS=("test -e test/file/path"
		"test -f test/file/path"
		"test -d test/file/path"
		"test -e integration_test.cpp"
		"test -f integration_test.cpp"
		"test -d integration_test.cpp"
		"test -f test_literal_tests.sh"
		"test -d dir"
		"test -e test/file/path && echo path exists"
		"echo test && test int_test"
		"test int_test || echo test "
		"(test -f int_test && test -e integration_test.cpp) || (echo testin && test something)"
		"test -a int_test"
		"teest int_test"
		"test"
		"test invalid"
)

for input in "${INPUTS[@]}"
do
        ./int_test "${input}"
done

