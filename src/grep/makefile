CC := gcc
CFLAGS := -std=c11 -Wall -Werror -Wextra
COLOUR = \033[00;32m
NC = \033[0m # No Color

all: s21_grep test check clean

s21_grep:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep

test:
	$(CC) $(CFLAGS) s21_grep_test.c -o test_grep
	@echo "${COLOUR}======================TESTS======================${NC}"
	# ./test_grep

check:
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@echo "${COLOUR}=====================CPPCHECK=====================${NC}"
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	@echo "${COLOUR}=======================STYLE=======================${NC}"
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
	@echo "${COLOUR}=======================LEAKS=======================${NC}"
	CK_FORK=no leaks -atExit -- ./test_grep

rebuild :
	clean
	make

clean:
	rm test_grep s21_grep *.cfg

valgrind:
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test_grep

