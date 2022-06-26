CC := gcc
CFLAGS := -Wall -Werror -Wextra
COLOUR = \033[00;32m
NC = \033[0m # No Color

all: s21_cat test check clean

s21_cat:
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

test:
	$(CC) $(CFLAGS) s21_cat_test.c -o test_cat
	@echo "${COLOUR}======================TESTS======================${NC}"
	# ./test_cat

clean:
	rm test_cat s21_cat *.cfg

check:
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@echo "${COLOUR}=====================CPPCHECK=====================${NC}"
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	@echo "${COLOUR}=======================STYLE=======================${NC}"
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
	@echo "${COLOUR}=======================LEAKS=======================${NC}"
	CK_FORK=no leaks -atExit -- ./test_cat

valgrind:
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test_cat