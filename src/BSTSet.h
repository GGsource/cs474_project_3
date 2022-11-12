#include "BSTNode.h"
class BSTSet {
  public:
	BSTSet();
	BSTSet(BSTSet &tree);
	~BSTSet();

	BSTNode *head;
	int set_size;

	void addString(const String &s);
	friend std::ostream &operator<<(std::ostream &os, const BSTSet &set);
};