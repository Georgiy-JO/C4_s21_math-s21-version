CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

LIBS = -lcheck -lm -lsubunit 
# без этой библиотеки  ^     не запускается у меня. хз почему

VALG = valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=RESULT_VALGRIND.txt ./
CPPCH = cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidFunctionArg --force

SRC_FILES = s21_abs_fabs_ceil_floor.c s21_cos_sin_tan.c s21_exp.c s21_ln.c s21_pow_sqrt.c s21_acos_asin_atan.c s21_fmod.c
OBJ_FILES = $(SRC_FILES:.c=.o)

HEAD_FILE = s21_math.h
LIBRARY = $(HEAD_FILE:.h=.a)

EXECUTABLE = s21_tests
GCOV_EXECUTABLE = s21_gcov_tests

TEST_SRC = tests.c
TEST_OBJ = $(TEST_SRC:.c=.o)

SRC_CL = ../materials/linters/.clang-format

all: $(LIBRARY)

# building static lib
$(LIBRARY): $(OBJ_FILES) $(HEAD_FILE)
	ar rcs $@ $^
	
# building objects for static lib
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# теперь цель сборки тестов выполняется аналогично вертеру
# verter output
# gcc -c test_math.c
# gcc -c main.c
# gcc -o unit_test test_math.o main.o ../../src/s21_math.a -lm
$(EXECUTABLE): $(TEST_SRC) $(LIBRARY)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(EXECUTABLE) $(LIBRARY) $(LIBS)

test: $(LIBRARY) $(EXECUTABLE)
	./$(EXECUTABLE)

# building file for gcov report
$(GCOV_EXECUTABLE): $(SRC_FILES) $(TEST_SRC)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $^ -o $@ $(LIBS)

# building gcov report
gcov_report: $(GCOV_EXECUTABLE)
	./$(GCOV_EXECUTABLE)
	gcov *.gcda
	gcovr -r . --html --html-details -o coverage_report.html
	rm -f *.gc* $(GCOV_EXECUTABLE)

valgrind: $(EXECUTABLE)
	$(VALG) $(EXECUTABLE)

cpp_check:
	$(CPPCH) $(SRC_FILES) $(HEAD_FILE)

clang_all:
	cp $(SRC_CL) .clang-format
	clang-format -i *.c
	clang-format -i *.h
	rm -f .clang-format

clean:
	rm -f $(EXECUTABLE) $(GCOV_EXECUTABLE) $(LIBRARY) *.gc* *.html *.css *.o

rebuild: clean all

.PHONY: all test clean gcov_report valgrind cpp_check clang_all
