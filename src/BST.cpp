#include "BSTSet.h"

BSTSet::BSTSet() { head = nullptr; }

BSTSet::BSTSet(BSTSet &tree) {
	// TODO: Implement copy constructor for BST
}

BSTSet::~BSTSet() {
	// TODO: Implement Desctructor for BST
}

// Tree node definition
BSTSet::BSTNode::BSTNode(String val) {
	value = val;
	leftChild = nullptr;
	rightChild = nullptr;
}

// Add string to the set
void BSTSet::addString(const String &s) {
	if (head == nullptr) {
		head = new BSTNode(s);
	} else {
		// TODO: There is already a head, find out where to place this string
		// TODO: Make sure this string is not a copy
	}
}