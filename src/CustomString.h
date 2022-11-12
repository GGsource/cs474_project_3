#include <ostream>

class CustomString {
  public:
	int size_;
	char *char_;
	// Default constructor
	CustomString();
	// Main constructor
	CustomString(const char charArray[]);
	// Copy Constructor
	CustomString(const CustomString &s);
	// Destructor
	~CustomString();
	// Combine Strings
	CustomString operator+(const CustomString &rString);
	// // Concatenate to string
	// String &operator+=(const String &rString);
	bool operator==(const CustomString &s) const;
	friend std::ostream &operator<<(std::ostream &os, const CustomString &s);
	bool operator<(const CustomString &s) const;
	bool operator>(const CustomString &s) const;
	void operator=(const CustomString &s) const;
};