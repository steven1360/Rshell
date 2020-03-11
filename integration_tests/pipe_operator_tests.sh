#!/bin/sh


#Test 1
echo "hakuna matata" > TESTFILE1.txt
./int_test "cat < TESTFILE1.txt | tr A-Z a-z | tee pipe_tf1.txt | tr a-z A-Z > pipe_tf2.txt"
cat "pipe_tf1.txt"
cat "pipe_tf2.txt"
rm TESTFILE1.txt
rm pipe_tf1.txt
rm pipe_tf2.txt


#Test 2
echo "tErRy TrUoNg" > TESTFILE1.txt
./int_test "cat < TESTFILE1.txt | tr a-z A-Z"
rm TESTFILE1.txt


#Test 3
./int_test "cat pipe_operator_tests.sh | grep txt"