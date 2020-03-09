#!/bin/sh



./int_test "ls > output_r_testfile1.txt"
cat "output_r_testfile1.txt"

./int_test "echo whatever > output_r_testfile2.txt"
cat "output_r_testfile2.txt"

./int_test "cat integration_test.cpp > output_r_testfile3.txt"
cat "output_r_testfile3.txt"

./int_test "ls -la > output_r_testfile4.txt"
cat "output_r_testfile4.txt"

./int_test "ls; echo first; idk && ls -la > output_r_testfile5.txt"
cat "output_r_testfile5.txt"

./int_test "echo terry && ( (fail || fail || fail && echo yes) || ls -la > output_r_testfile6.txt)"
cat "output_r_testfile6.txt"
