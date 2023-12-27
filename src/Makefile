CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 --coverage
LIBS = -lcheck -lsubunit -lm

# src
SRC_FILES = s21_abs_fabs_ceil_floor.c s21_cos_sin_tan.c s21_exp.c s21_ln.c s21_pow_sqrt.c s21_acos_asin_atan.c s21_fmod.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# static lib
STATIC_LIBRARY = s21_math.a
# tests
EXECUTABLE = s21_tests

# test src
TEST_SRC = tests.c
TEST_OBJ = $(TEST_SRC:.c=.o)

# format src
SRC_CL=../materials/linters/.clang-format

all: s21_math.a $(EXECUTABLE) test gcov_report

# build static lib
s21_math.a: $(OBJ_FILES)
	ar rcs $(STATIC_LIBRARY) $(OBJ_FILES)

# build tests
$(EXECUTABLE): $(STATIC_LIBRARY) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(EXECUTABLE) $(STATIC_LIBRARY) $(LIBS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

# run tests
test: $(EXECUTABLE)
	rm -f *.o
	./$(EXECUTABLE)

# coverage test
coverage: test
	gcov s21_*.gcda

gcov_report: coverage
	lcov -c -d . -o s21_math.info
	genhtml -o ./report s21_math.info

valgrind: $(EXECUTABLE)
	$(VALG)$(EXECUTABLE)
	rm -f *.gc* *.o

cpp_check: 
	$(CPPCH) *.c *.h

# format code style
clang_all:
	cp $(SRC_CL) .clang-format
	clang-format -i *.c
	clang-format -i *.h
	rm -f .clang-format

clean:
	rm -f $(EXECUTABLE) $(STATIC_LIBRARY) *.gc* *.html *.css *.o s21_math.info
	rm -rf report

rebuild: clean all

.PHONY: all test clean s21_math.a gcov_report
