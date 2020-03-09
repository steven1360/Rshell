#!/bin/sh


echo "terry truong steven jung" > "input_r_testfile1.txt"
./int_test "cat < input_r_testfile1.txt"


echo "lol" > "input_r_testfile2.txt"
./int_test "cat < input_r_testfile2.txt"



echo "" > "input_r_testfile3.txt"
./int_test "cat < input_r_testfile3.txt"

echo "one
	  two
	  three
	  four" > "input_r_testfile4.txt"
./int_test "wc -l < input_r_testfile4.txt"

echo "me is echo haha" > "input_r_testfile5.txt"
./int_test "cat < input_r_testfile5.txt && echo one || idk"

echo "me is echo haha" > "input_r_testfile6.txt"
./int_test "echo \"the first echo\" && (invalid || cat < input_r_testfile6.txt)"

