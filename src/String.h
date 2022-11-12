#include <ostream>

class String {
  public:
	int size_;
	char *char_;
	// Main constructor
	String(const char charArray[]);
	// Copy Constructor
	String(const String &s);
	// Destructor
	~String();
	// Combine Strings
	String operator+(const String &rString);
	// // Concatenate to string
	// String &operator+=(const String &rString);
	bool operator==(const String &s) const;
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	bool operator<(const String &s) const;
	bool operator>(const String &s) const;
	// void operator=(const String &s) const;
};