#include "String.h"
class BSTSet {
  public:
	class BSTNode {
	  public:
		String value;
		BSTNode *leftChild;
		BSTNode *rightChild;
		BSTNode(String val);
		// TODO: Check if we need a custom  destructor here
	};

	BSTSet();
	BSTSet(BSTSet &tree);
	~BSTSet();

	BSTNode *head;
	int set_size;

	void addString(const String &s);
	friend std::ostream &operator<<(std::ostream &os, const BSTSet &set);
};