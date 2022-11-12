#include "../src/BSTSet.h"
#include <iostream>

int main() {
	CustomString s1("I am string 1");
	CustomString s2("And I am string 2!!");
	CustomString s3(s1 + s2);
	// DONE: String constructor tested
	// DONE: String Copy Constructor tested
	// DONE: String concatenation tested
	// DONE: String Destructor tested
	//
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	std::cout << "s3: " << s3 << std::endl;

	BSTSet set1;
	std::cout << "Empty BSTSet Set1: " << set1 << std::endl;
	set1.addString("OBAMNA!!!");

	std::cout << "is set1.head null? " << (set1.head == nullptr) << std::endl;

	std::cout << "set1.head->value is " << set1.head->value << std::endl;

	std::cout << "Set1 after adding 1 string: " << set1 << std::endl;
}