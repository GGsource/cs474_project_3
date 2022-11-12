#include "CustomString.h"
#include <iostream>
#include <string.h>
// Custom String class

// Default constructor - empty string object
CustomString::CustomString() {
	this->size_ = 0;
	this->char_ = new char[1]{'\0'};
}

// Main constructor - takes char array to initialize
CustomString::CustomString(const char charArray[]) {
	this->size_ = strlen(charArray);
	// std::cout << "array size is: " << size_ << std::endl;
	this->char_ = new char[size_ + 1];
	for (int i = 0; i < size_; i++) {
		char_[i] = charArray[i];
	}
	char_[size_] = '\0';
	// std::cout << "array is now: " << char_ << std::endl;
}
// DONE: copy constructor
CustomString::CustomString(const CustomString &s) : CustomString(s.char_) {}

// DONE: destructor
CustomString::~CustomString() { delete[] char_; }

// DONE: concatenation of 2 strings
CustomString CustomString::operator+(const CustomString &rString) {
	int newSize = this->size_ + rString.size_;
	char newArr[newSize];
	newArr[newSize] = '\0'; // Set the end to terminate
	for (int i = 0; i < this->size_; i++) {
		newArr[i] = this->char_[i];
	}
	for (int i = this->size_; i < newSize; i++) {
		newArr[i] = rString.char_[i - (this->size_)];
	}
	return CustomString(newArr);
};
// 	// Concatenate to string
// String& String::operator += (const String& rString) {

// };

bool CustomString::operator==(const CustomString &s) const {
	// DONE: Implement comparison of strings
	if (s.size_ != this->size_) // If they're different sizes they're not equal
		return false;
	for (int i = 0; i < size_; i++) { // If letters aren't identical, not equal
		if (this->char_[i] != s.char_[i])
			return false;
	}
	return true; // All was same, they're equal!
}

std::ostream &operator<<(std::ostream &os, const CustomString &s) {
	// DONE: Make String function with std::cout
	return os << s.char_;
}

bool CustomString::operator<(const CustomString &s) const {
	// DONE: Implement less than comparison
	const CustomString *smallest;
	int min;
	if (this->size_ <= s.size_) {
		smallest = this;
	} else {
		smallest = &s;
	}
	min = smallest->size_;
	for (int i = 0; i < min; i++) {
		if (this->char_[i] < s.char_[i])
			return true;
		else if (this->char_[i] > s.char_[i])
			return false;
		// Else do nothing, these letters were equal, check next one
	}
	// If we got here, all the letters were equal up to  the smallest's length,
	// so the smaller string is less than the longer one
	if (smallest == this)
		return true;
	else
		return false;
}
bool CustomString::operator>(const CustomString &s) const {
	// DONE: Implement greater than comparison
	const CustomString *smallest;
	int min;
	if (this->size_ <= s.size_) {
		smallest = this;
	} else {
		smallest = &s;
	}
	min = smallest->size_;
	for (int i = 0; i < min; i++) {
		if (this->char_[i] > s.char_[i])
			return true;
		else if (this->char_[i] < s.char_[i])
			return false;
		// Else do nothing, these letters were equal, check next one
	}
	// If we got here, all the letters were equal up to  the smallest's length,
	// so the smaller string is less than the longer one
	if (smallest == this)
		return false;
	else
		return true;
}