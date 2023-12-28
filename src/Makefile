CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

LIBS = -lcheck -lm

# check
VALG = valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=RESULT_VALGRIND.txt ./
CPPCH = cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidFunctionArg --force 

# src
SRC_FILES = s21_abs_fabs_ceil_floor.c s21_cos_sin_tan.c s21_exp.c s21_ln.c s21_pow_sqrt.c s21_acos_asin_atan.c s21_fmod.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# static lib
HEAD_FILE = s21_math.h
LIBRARY = $(HEAD_FILE:.h=.a)

# tests
EXECUTABLE = s21_tests

# test src
TEST_SRC = $(SRC_FILES) tests.c
TEST_OBJ = $(TEST_SRC:.c=.o)

# format src
SRC_CL=../materials/linters/.clang-format

all: $(LIBRARY)

# build static lib
$(LIBRARY): $(OBJ_FILES) $(HEAD_FILE)
	ar rcs $@ $^
	rm -f *.o

# build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# build test file
$(EXECUTABLE): $(TEST_SRC) $(LIBRARY)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $^ -o $(EXECUTABLE) $(LIBRARY) $(LIBS)

# run tests
test: $(EXECUTABLE)
	./$(EXECUTABLE)

# coverage test
coverage: test
	gcov $(TEST_SRC)

gcov_report: coverage
	gcovr -r . --html --html-details -o coverage_report.html
	rm -f *.gc* *.o

valgrind: $(EXECUTABLE)
	$(VALG) $(EXECUTABLE)
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
	rm -f $(EXECUTABLE) $(LIBRARY) *.gc* *.html *.css *.o

rebuild: clean all

.PHONY: all test clean s21_math.a gcov_report