all: compile run

compile:
	g++ .\src\main.cpp .\src\String.cpp -Wall -o output.exe
run:
	output.exe
clean:
	erase *.exe