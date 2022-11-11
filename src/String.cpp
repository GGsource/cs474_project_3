#include "String.h"
#include <iostream>
#include <string.h>
// Custom String class

// Main constructor - takes char array to initialize
String::String(const char charArray[]) {
	this->size_ = strlen(charArray);
	std::cout << "array size is: " << size_ << std::endl;
	this->char_ = new char[size_ + 1];
	for (int i = 0; i < size_; i++) {
		char_[i] = charArray[i];
	}
	char_[size_] = '\0';
	std::cout << "array is now: " << char_ << std::endl;
}
// copy constructor
String::String(const String &s) : String(s.char_) {}

// destructor
String::~String() { delete[] char_; }

// IDEA: String concatenation for making coloring console output easy
// String String::operator+ (const String& rString) {
// 	String s()
// };
// 	// Concatenate to string
// String& String::operator += (const String& rString) {

// };