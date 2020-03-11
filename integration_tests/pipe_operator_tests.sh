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


#test 4
./int_test "ls | head -3 | tail -5"


#test 5
./int_test "ls | head -3 | tail -5 > file.txt"
cat file.txt
rm file.txt

#test 6
./int_test "ls *.sh | xargs wc"

#test 7
./int_test "ls -l | grep sh | wc -l"

#test 8
./int_test "ls | rev | cut -d'.' -f1 | rev | sort | uniq -c"


#bad inputs

#test 9
./int_test "ls | hfdsfead -3 | tail -5dsfds"

#test 10
./int_test "ls -l | | grep sh | wc -l"

#test 11
./int_test "(cat filethatdoesntexist) | grep txt || echo testing"

#test 12
./int_test "echo this is an echo && ( | (echo test) || | ||)"

#test 13
./int_test "| ls; |"