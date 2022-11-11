#include "String.h"

class BSTSet {
  public:
	BSTSet();
	BSTSet(BSTSet &tree);
	~BSTSet();

	class BSTNode {
	  public:
		BSTNode(String val);

		String value = nullptr;
		BSTNode *leftChild;
		BSTNode *rightChild;
	};

	BSTNode *head;

  public:
	void addString(const String &s);
};