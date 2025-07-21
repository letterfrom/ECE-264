CC = gcc

# compiles to debug
CFLAGS	= -std=c11 -Wall -Wshadow -Werror -Wvla -g -pedantic -fstack-protector-strong --param ssp-buffer-size=1

# if you want to compile with the -O3 optimization flag, comment the preceding CFLAGS
# and use the following CFLAGS

# CFLAGS = -std=c11 -Wall -Wshadow -Werror -Wvla -O3 -pedantic -fstack-protector-strong --param ssp-buffer-size=1

# coverage flags
COV_FLAGS = -ftest-coverage -fprofile-arcs -dumpbase ''

hw09: hw09.o main.o
	$(CC) $(CFLAGS) hw09.o main.o -o hw09

coverage: 
	rm -f *.gcno *.gcda *.c.gcov hw09_cov
	$(CC) $(CFLAGS) $(COV_FLAGS) hw09.c main.c -o hw09_cov
	./hw09_cov
	gcov -f hw09.c

# run valgrind
memory: hw09
	valgrind -s --leak-check=full ./hw09

# clean rule
clean:
	rm -f *.o *.gcno *.gcda *.c.gcov hw09 hw09_cov

%.o: %.c
	$(CC) $(CFLAGS) -c $<
