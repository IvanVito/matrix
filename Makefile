CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OS = $(shell uname)

ifeq ($(OS),Linux)
    det_OS = -lcheck -lrt -lpthread -lsubunit
else
    det_OS = -lcheck -lpthread
endif

all: clean matrix.a test gcov_report

check:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -i *.c *.h
	rm .clang-format
	cppcheck --enable=all --suppress=MissingIncludeSystem *.c *.h

s21_matrix: 
	$(CC) $(CFLAGS) s21_matrix.c  s21_matrix.h -o s21_matrix $(det_OS)

test: 
	$(CC) $(CFLAGS) --coverage all_test.c s21_matrix.c -o test $(det_OS)

matrix.a: s21_matrix.o
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

s21_matrix.o: s21_matrix.h s21_matrix.c
	$(CC) $(CFLAGS) s21_matrix.c -c 

gcov_report: test
	./test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html

clean:
	rm -rf report *.gc* *.o *.info *.a test.dSYM test s21_matrix.dSYM s21_matrix

rebuild: clean all

.PHONY: all check test gcov_report clean rebuild