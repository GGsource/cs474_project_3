# CS 474's Project 3: Binary Search Tree Set Calculator

## Author: Geo Gonzalez

##### Finished: 11/12/2022

## Project Description
This Set Calculator helps the user easily perform operations on a pair of word sets while seeing the results in real time through a command line interface. All available commands are presented and explained on startup.

## Folder Structure Explanation:

> src folder - Contains the main .h and .cpp files needed to run the project. BSTSet, CustomString, and colorize, are all files that main depends on. Main holds the main loop of the program.

> tests folder - Contains initial tests to make sure functionality was correct.

> utils folder - Contains assignment PDF detailing requirements.

## Root level files

> .clang-format & gitignore - irrelevant to the program's running, used only locally.

> makefile - simple and easy way to run project with just a single word command.

## How to run project:

### Option A
1. Using Docker, open project in Dev Container. Type `make` in command line to run project.

### Option B

1. If Make is intalled on the local machine, simply typing `make` on the command line will run the project.
2. If Make is not installed but chocolatey package manager is, make can be installed with `choco install make`.

### Option C

1. If neither of these is an option, the project can be compiled directly by typing the following on the command line: `g++ .\src\main.cpp .\src\colorize.cpp .\src\CustomString.cpp .\src\BSTSet.cpp -Wall -o output.exe`.
2. Now that it is compiled, do `.\output.exe` to run the compiled file.

Commands for using the BST Set calculator are presented when the program begins and after every loop.
