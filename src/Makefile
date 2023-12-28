CC = gcc
GENLAGS = -Wall -Wextra -Werror -std=c11
REPLAGS =-fprofile-arcs -ftest-coverage #-g
LIBS = -lcheck  -lm #-lsubunit
VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=RESULT_VALGRIND.txt ./
#VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./
CPPCH = cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidFunctionArg --force 
DFLAG = -D_POSIX_C_SOURCE=200809L

SRC_FILES = s21_abs_fabs_ceil_floor.c s21_cos_sin_tan.c s21_exp.c s21_ln.c s21_pow_sqrt.c s21_acos_asin_atan.c s21_fmod.c
SRC_FILES_TST = $(SRC_FILES:.c=.tst.c)
HEAD_FILE = s21_math.h
OBJ_FILES_TEST = $(SRC_FILES:.c=.tst.o)
OBJ_FILES = $(SRC_FILES:.c=.o)

# static lib
LIBRARY = $(HEAD_FILE:.h=.a)
TESTLIBRARY = $(HEAD_FILE:.h=.tst.a)
# tests
EXECUTABLE = s21_tests

# test src
TEST_SRC = tests.c
TEST_OBJ = $(TEST_SRC:.c=.o)

# format src
SRC_CL=../materials/linters/.clang-format

all: s21_math.a #$(EXECUTABLE) test gcov_report

# build static lib
s21_math.a: $(OBJ_FILES)
	ar rcs $(LIBRARY) $(OBJ_FILES)
	rm -f *.o

s21_math.tst.a: $(OBJ_FILES_TEST)
	ar rcs $(TESTLIBRARY) $(OBJ_FILES_TEST)
	rm -f *.o	

# build tests
$(EXECUTABLE): $(TESTLIBRARY) $(TEST_OBJ)
	$(CC) $(GENLAGS) $(REPLAGS) $(DFLAG) $(TEST_OBJ) -o $(EXECUTABLE) $(TESTLIBRARY) $(LIBS)

%.o: %.c $(HEAD_FILE)
	$(CC) $(GENLAGS) $(DFLAG) -c $< -o $@

%.tst.o: %.c $(HEAD_FILE)
	$(CC) $(GENLAGS) $(REPLAGS) $(DFLAG) -c $< -o $@

# run tests
test: $(EXECUTABLE)
	rm -f *.o
	./$(EXECUTABLE)

# coverage test
coverage: test
	gcov $(SRC_FILES_TST)
#	gcov  *.tst.c

gcov_report: coverage
	gcovr -r . --html --html-details -o coverage_report.html
	rm -f *.tst.gc* *.o

valgrind: $(EXECUTABLE)
	$(VALG)$(EXECUTABLE)
	rm -f *.tst.gc* *.o

cpp_check: 
	$(CPPCH) *.c *.h

# format code style
clang_all:
	cp $(SRC_CL) .clang-format
	clang-format -i *.c
	clang-format -i *.h
	rm -f .clang-format

clean:
	rm -f $(EXECUTABLE) *.a *.gc* *.html *.css *.o

rebuild: clean all

.PHONY: all test clean s21_math.a gcov_report
