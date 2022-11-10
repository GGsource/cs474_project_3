#include "string.h"
int main() {
	String s(new char[5]{'a', 'b', 'c', 'd', '\0'});

	String s2(s);

	String s3("OBAMNA");

	return 0;
}