#include "colorize.h"
class BSTSet {
  public:
	class BSTNode {
	  public:
		CustomString value;
		BSTNode *leftChild;
		BSTNode *rightChild;
		BSTNode(CustomString val);
	};

	BSTSet();
	BSTSet(BSTSet &tree);
	~BSTSet();

	BSTNode *head;
	int set_size;

	void addString(const CustomString &s);
	friend std::ostream &operator<<(std::ostream &os, const BSTSet &set);

	void clear();
	void recursiveDestruction(const BSTNode *head);
	void swap(BSTSet &s2);
	bool contains(const CustomString &s) const;
	bool isProperSubset(const BSTSet &s2);
	void recursiveCopy(BSTNode *node);
	void recursiveIntersect(BSTNode *node, BSTSet *s3);
};