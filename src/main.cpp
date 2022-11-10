#include "string.h"
#include <iostream>

int main() {

	char input;
	bool isEnded = false;
	while (!isEnded) {
		// TODO: Make this a print instructions class
		// TODO: change to do while that calls print in do and at the end of
		// while
		std::cout << "Welcome to CS 474 Project 3" << std::endl;
		std::cout << "e - Erase set. This command allows interactive users to "
					 "delete the current S1 set. The previous value stored in "
					 "S1 is lost forever."
				  << std::endl;
		std::cout << "s - Switch sets. The sets associated with S1 and S2 are "
					 "swapped, meaning that S1 will receive the previous S2 "
					 "set and vice versa."
				  << std::endl;
		std::cout
			<< "b - Subset operation. This command compares S1 and S2 and "
			   "prints an appropriate message on the console indicating "
			   "whether S2 is a proper subset of S2. Two strings are deemed to "
			   "be equal if they have the same length and content; however, "
			   "the comparison is case sensitive. S1 and S2 are not modified"
			<< std::endl;
		std::cout
			<< "c - Copy set. Set S1 is deep copied into S2. The previous "
			   "content of S2 is deleted. The content of S1 is not affected. "
			   "The two sets must not share any data structures, that is, they "
			   "can be modified independently of each other."
			<< std::endl;
		std::cout << "l - List set contents. The string values stored in the "
					 "two sets are printed on the standard output stream in "
					 "alphabetical order. The two sets are not modified."
				  << std::endl;
		std::cout
			<< "a - Add element. This function allows a user to add a new "
			   "string to S1. The value is obtained through an appropriate "
			   "prompt with an interactive user. No action is taken if the "
			   "string in question is already in the set. The insertion should "
			   "preserve the BST properties of S1."
			<< std::endl;
		std::cout
			<< "u - Union. This element takes the set union of S1 and S2 and "
			   "stores the resulting value in S1. The previous content of S1 "
			   "is lost. S2 is not modified by this operation."
			<< std::endl;
		std::cout << "i - Intersection. This command takes the set "
					 "intersection of S1and S2 and stores the resulting value "
					 "in S1. The previous content of S1 is overriden. S2 is "
					 "not modified by this operation."
				  << std::endl;
		std::cout << "q - Prints sets S1 and S2 and quits the set manager."
				  << std::endl;

		std::cout << "Please enter your command: ";
		std::cin >> input;
		switch (input) {
		case 'q':
			isEnded = true;
		default:
			break;
		}
		std::cout << "Your input was " << input << std::endl;
	}
	std::cout << "Exiting program, goodbye!" << std::endl;
	return 0;
}