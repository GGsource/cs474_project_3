all: compile run

tests: compile_tests run_tests

compile:
	g++ .\src\main.cpp .\src\colorize.cpp .\src\CustomString.cpp .\src\BSTSet.cpp -Wall -o output.exe
run:
	output.exe

compile_tests:
	g++ .\tests\tests.cpp .\src\colorize.cpp .\src\CustomString.cpp .\src\BSTSet.cpp -Wall -o tests.exe
run_tests:
	tests.exe

clean:
	erase *.exe