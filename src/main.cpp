#include "BSTSet.h"
#include <iostream>
// Function to print the instructions for the user
void printInstructions() {
	std::cout << colorText("	e - Erase set", "34")
			  << ". This command allows "
				 "interactive users to "
				 "delete the current S1 set. The previous value stored in "
				 "S1 is lost forever."
			  << std::endl;
	std::cout << colorText("	s - Switch sets", "34")
			  << ". The sets associated with "
				 "S1 and S2 are "
				 "swapped, meaning that S1 will receive the previous S2 "
				 "set and vice versa."
			  << std::endl;
	std::cout
		<< colorText("	b - Subset operation", "34")
		<< ". This command compares S1 "
		   "and S2 and "
		   "prints an appropriate message on the console indicating "
		   "whether S2 is a proper subset of S1. Two strings are deemed to "
		   "be equal if they have the same length and content; however, "
		   "the comparison is case sensitive. S1 and S2 are not modified"
		<< std::endl;
	std::cout
		<< colorText("	c - Copy set", "34")
		<< ". Set S1 is deep copied into S2. "
		   "The previous "
		   "content of S2 is deleted. The content of S1 is not affected. "
		   "The two sets must not share any data structures, that is, they "
		   "can be modified independently of each other."
		<< std::endl;
	std::cout << colorText("	l - List set contents", "34")
			  << ". The string values "
				 "stored in the "
				 "two sets are printed on the standard output stream in "
				 "alphabetical order. The two sets are not modified."
			  << std::endl;
	std::cout
		<< colorText("	a - Add element", "34")
		<< ". This function allows a user to "
		   "add a new "
		   "string to S1. The value is obtained through an appropriate "
		   "prompt with an interactive user. No action is taken if the "
		   "string in question is already in the set. The insertion should "
		   "preserve the BST properties of S1."
		<< std::endl;
	std::cout << colorText("	u - Union", "34")
			  << ". This element takes the set union of "
				 "S1 and S2 and "
				 "stores the resulting value in S1. The previous content of S1 "
				 "is lost. S2 is not modified by this operation."
			  << std::endl;
	std::cout << colorText("	i - Intersection", "34")
			  << ". This command takes the set "
				 "intersection of S1 and S2 and stores the resulting value "
				 "in S1. The previous content of S1 is overriden. S2 is "
				 "not modified by this operation."
			  << std::endl;
	std::cout << colorText("	q - Quit", "34")
			  << ". Prints sets S1 and S2 and quits "
				 "the set manager."
			  << std::endl;
}

int main() {

	std::cout << colorText("Welcome to CS 474 Project 3! Please select from "
						   "the available commands below.",
						   "35")
			  << std::endl
			  << std::endl;
	BSTSet *s1 = new BSTSet;
	BSTSet *s2 = new BSTSet;
	bool isEnded = false;
	while (!isEnded) {
		std::cout << colorText("s1: ", "33") << *s1 << std::endl
				  << colorText("s2: ", "33") << *s2 << std::endl
				  << std::endl;
		printInstructions();
		std::cout << std::endl << "Please enter your command: ";
		char input;
		std::cin >> input;
		std::cout << std::endl;
		switch (input) {
		case 'e': // Erase S1
			s1->clear();
			std::cout << colorText("Erased contents of s1.", "32") << std::endl;
			break;
		case 's': // Swap sets by switching pointers
			s1->swap(*s2);
			std::cout << colorText("Swapped contents of s1 & s2.", "32")
					  << std::endl;
			break;
		case 'b': // print whether or not its a proper subset
			if (s1->isProperSubset(*s2)) {
				std::cout << colorText("S2 is a proper subset of S1.", "32")
						  << std::endl;
			} else
				std::cout << colorText("S2 is NOT a proper subset of S1.", "31")
						  << std::endl;
			break;
		case 'c':
			s2 = new BSTSet(*s1);
			std::cout << colorText("Copied s1 to s2.", "32") << std::endl;
			break;
		case 'l':
			std::cout << colorText("Listing out current BSTs:", "32")
					  << std::endl;
			std::cout << colorText("	s1: ", "33") << *s1 << std::endl
					  << colorText("	s2: ", "33") << *s2 << std::endl;
			break;
		case 'a': {
			char newString[25]{};
			std::cout << colorText("Specify string to add: ", "36");
			std::cin >> newString;
			s1->addString(newString);
			std::cout << colorText("Added ", "32") << colorText(newString, "32")
					  << colorText(" to s1.", "32") << std::endl;
		} break;
		case 'u':
			s1->recursiveCopy(s2->head);
			break;
		case 'i': {
			BSTSet *s3 = new BSTSet;
			s1->recursiveIntersect(s2->head, s3);
			s1 = s3;
			std::cout << colorText("Intersection of s1 & s2 placed into s1.",
								   "32")
					  << std::endl;
		} break;
		case 'q':
			isEnded = true;
			std::cout << "quitting program, final Sets were:" << std::endl;
			std::cout << colorText("s1: ", "33") << (*s1) << std::endl
					  << colorText("s2: ", "33") << *s2 << std::endl
					  << std::endl;
			break;
		default:
			std::cout << colorText("command not recognized, try again.", "31")
					  << std::endl;
			break;
		}
		std::cout << std::endl;
	}
	std::cout << colorText("Exiting, goodbye!", "32") << std::endl;
	return 0;
}