# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

SRCS = main.c filechar.c fileint.c
OBJS = $(SRCS:%.c=%.o)

hw02: $(OBJS) 
	$(GCC) $(OBJS) -o hw02

.c.o: 
	$(GCC) -c ./$*.c 

testall: test1 test2 test3 test4

test1: hw02
	./hw02 inputs_char/2016 inputs_int/input1 > output16
	diff output16 expected_char/expected16
	diff sum_output.txt expected_int/expected1

test2: hw02
	./hw02 inputs_char/2017 inputs_int/input2 > output17
	diff output17 expected_char/expected17
	diff sum_output.txt expected_int/expected2

test3: hw02
	./hw02 inputs_char/2018 inputs_int/input3 > output18
	diff output18 expected_char/expected18
	diff sum_output.txt expected_int/expected3

test4: hw02
	./hw02 inputs_char/2019 inputs_int/input4> output19
	diff output19 expected_char/expected19
	diff sum_output.txt expected_int/expected4

clean: # remove all machine generated files
	rm -f hw02 *.o output?? sum_output.txt


