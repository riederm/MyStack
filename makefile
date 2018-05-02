CFLAGS  = -std=c99
CFLAGS += -g
#CFLAGS += -Wall
CFLAGS += -Wextra
#CFLAGS += -pedantic
#CFLAGS += -Werror

CC = gcc

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test, all: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/test_mystack.c src/mystack.c src/mystack.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/mystack.c test/vendor/unity.c test/test_mystack.c -o tests.out
