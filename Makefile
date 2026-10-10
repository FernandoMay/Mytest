CC      ?= cc
CFLAGS  ?= -Wall -Wextra -std=c99 -O2

.PHONY: all test run clean

all: hello

hello.o: hello.c hello.h
	$(CC) $(CFLAGS) -c hello.c -o hello.o

main.o: main.c hello.h
	$(CC) $(CFLAGS) -c main.c -o main.o

hello: main.o hello.o
	$(CC) $(CFLAGS) main.o hello.o -o hello

test: test_hello.c hello.c
	$(CC) $(CFLAGS) test_hello.c hello.c -o /tmp/mytest_tests
	/tmp/mytest_tests
	@rm -f /tmp/mytest_tests

run: hello
	./hello
	./hello Fernando

clean:
	rm -f hello *.o /tmp/mytest_tests
