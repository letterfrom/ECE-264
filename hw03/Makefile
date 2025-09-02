WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR) 

SRCS = main.c count_words.c
OBJS = $(SRCS:%.c=%.o)

count_words: $(OBJS) 
	$(GCC) $(OBJS) -o count_words

.c.o: 
	$(GCC) -c $*.c 

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9

test1: count_words
	./count_words inputs/test1 aa >> output1
	diff output1 expected/expected1

test2: count_words
	./count_words inputs/test2 abc >> output2
	diff output2 expected/expected2

test3: count_words
	./count_words inputs/test3 I >> output3
	diff output3 expected/expected3

test4: count_words
	./count_words inputs/test4 and >> output4
	diff output4 expected/expected4

test5: count_words
	./count_words inputs/test5 clock >> output5
	diff output5 expected/expected5

test6: count_words
	./count_words inputs/test6 pink >> output6
	diff output6 expected/expected6

test7: count_words
	./count_words inputs/test7 noodle >> output7
	diff output7 expected/expected7

test8: count_words
	./count_words inputs/test8 lucky >> output8
	diff output8 expected/expected8

test9: count_words
	./count_words inputs/test9 vial >> output9
	diff output9 expected/expected9

leak: count_words
	valgrind ./count_words inputs/test9 vial

clean: # remove all machine generated files
	rm -f count_words *.o *.txt output*