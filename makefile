ifeq ($(OS), Windows_NT)
	COMPILATION = g++ .\src\main.cpp .\src\colorize.cpp .\src\CustomString.cpp .\src\BSTSet.cpp -Wall -o output.exe
	COMP_RUN = output.exe
	COMP_TESTS = g++ .\tests\tests.cpp .\src\colorize.cpp .\src\CustomString.cpp .\src\BSTSet.cpp -Wall -o tests.exe
	COMP_RUN_TESTS = tests.exe
	RM = rm -force -recurse -verbose *.exe
else
	COMPILATION = g++ ./src/main.cpp ./src/colorize.cpp ./src/CustomString.cpp ./src/BSTSet.cpp -Wall -o output.exe
	COMP_RUN = ./output.exe
	COMP_TESTS = g++ ./tests/tests.cpp ./src/colorize.cpp ./src/CustomString.cpp ./src/BSTSet.cpp -Wall -o tests.exe
	COMP_RUN_TESTS = ./tests.exe
	RM = rm -rfv *.exe	

all: compile run

tests: compile_tests run_tests

compile:
	$(COMPILATION)
run:
	$(COMP_RUN)
compile_tests:
	$(COMP_TESTS)
run_tests:
	$(COMP_RUN_TESTS)
clean:
	$(RM)

endif