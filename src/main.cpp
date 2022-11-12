#include "BSTSet.h"
#include <iostream>

// Colorize console output
CustomString colorText(const char *c) {
	return CustomString(CustomString("\x1B[94m") + CustomString(c) +
						CustomString("\033[0m"));
};

// Function to print the instructions for the user
void printInstructions() {
	std::cout << "\x1B[94me - Erase set\033[0m. This command allows "
				 "interactive users to "
				 "delete the current S1 set. The previous value stored in "
				 "S1 is lost forever."
			  << std::endl;
	std::cout << "\x1B[94ms - Switch sets\033[0m. The sets associated with "
				 "S1 and S2 are "
				 "swapped, meaning that S1 will receive the previous S2 "
				 "set and vice versa."
			  << std::endl;
	std::cout
		<< "\x1B[94mb - Subset operation\033[0m. This command compares S1 "
		   "and S2 and "
		   "prints an appropriate message on the console indicating "
		   "whether S2 is a proper subset of S2. Two strings are deemed to "
		   "be equal if they have the same length and content; however, "
		   "the comparison is case sensitive. S1 and S2 are not modified"
		<< std::endl;
	std::cout
		<< "\x1B[94mc - Copy set\033[0m. Set S1 is deep copied into S2. "
		   "The previous "
		   "content of S2 is deleted. The content of S1 is not affected. "
		   "The two sets must not share any data structures, that is, they "
		   "can be modified independently of each other."
		<< std::endl;
	std::cout << "\x1B[94ml - List set contents\033[0m. The string values "
				 "stored in the "
				 "two sets are printed on the standard output stream in "
				 "alphabetical order. The two sets are not modified."
			  << std::endl;
	std::cout
		<< "\x1B[94ma - Add element\033[0m. This function allows a user to "
		   "add a new "
		   "string to S1. The value is obtained through an appropriate "
		   "prompt with an interactive user. No action is taken if the "
		   "string in question is already in the set. The insertion should "
		   "preserve the BST properties of S1."
		<< std::endl;
	std::cout
		<< "\x1B[94mu - Union\033[0m. This element takes the set union of "
		   "S1 and S2 and "
		   "stores the resulting value in S1. The previous content of S1 "
		   "is lost. S2 is not modified by this operation."
		<< std::endl;
	std::cout << "\x1B[94mi - Intersection\033[0m. This command takes the set "
				 "intersection of S1and S2 and stores the resulting value "
				 "in S1. The previous content of S1 is overriden. S2 is "
				 "not modified by this operation."
			  << std::endl;
	std::cout << "\x1B[94mq - Quit\033[0m. Prints sets S1 and S2 and quits "
				 "the set manager."
			  << std::endl;
}

int main() {
	std::cout << colorText("Welcome to CS 474 Project 3") << std::endl;
	BSTSet s1;
	BSTSet s2;
	bool isEnded = false;
	while (!isEnded) {
		printInstructions();
		// TODO: Make the sets printing be green or something else
		std::cout << "s1: " << s1 << std::endl << "s2: " << s2 << std::endl;
		std::cout << std::endl << "Please enter your command: ";
		char input;
		std::cin >> input;
		char newString[20]{}; // FIXME: should not be 20, should depend on input
		switch (input) {
		case 'e': // Erase S1
			s1.clear();
			break;
		case 's': // Swap sets by switching pointers
			s1.swap(s2);
			break;
		case 'b':
			std::cout << input << " command not yet implemented..."
					  << std::endl; // DELETEME
			break;
		case 'c':
			std::cout << input << " command not yet implemented..."
					  << std::endl; // DELETEME
			break;
		case 'l':
			std::cout << input << " command not yet implemented..."
					  << std::endl; // DELETEME
			break;
		case 'a':
			std::cout << "Specify string to add: ";
			std::cin >> newString;
			s1.addString(newString);
			break;
		case 'u':
			std::cout << input << " command not yet implemented..."
					  << std::endl; // DELETEME
			break;
		case 'i':
			std::cout << input << " command not yet implemented..."
					  << std::endl; // DELETEME
			break;
		case 'q':
			isEnded = true;
			std::cout << "quitting program, final Sets were:" << std::endl;
			std::cout << "s1: " << s1 << std::endl
					  << "s2: " << s2 << std::endl
					  << std::endl;
			break;
		default:
			std::cout << input << " command not recognized, try again."
					  << std::endl;
			break;
		}
		// DEBUGGING:
	}
	std::cout << "Exiting, goodbye!" << std::endl; // IDEA: Colorme
	return 0;
}