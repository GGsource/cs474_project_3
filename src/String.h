class String {
  public:
	int size_;
	char *char_;
	// Main constructor
	String(const char charArray[]);
	// Copy Constructor
	String(const String &s);
};