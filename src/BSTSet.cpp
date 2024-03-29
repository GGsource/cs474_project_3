#include "BSTSet.h"
#include <iostream>
#include <ostream>

BSTSet::BSTNode::BSTNode(CustomString val) : value(val) {
	// std::cout << "Entered BSTNode constructor!" << std::endl; // DEBUGGING:
	leftChild = nullptr;
	rightChild = nullptr;
	// std::cout << "Successfully got through BSTNode constructor!"
	// 		  << std::endl; // DEBUGGING:
}

BSTSet::BSTSet() {
	head = nullptr;
	set_size = 0;
}

void BSTSet::recursiveCopy(BSTSet::BSTNode *node) {
	if (node == nullptr)
		return;
	this->addString(node->value);
	recursiveCopy(node->leftChild);
	recursiveCopy(node->rightChild);
}

void BSTSet::recursiveIntersect(BSTNode *node, BSTSet *s3) {
	if (node == nullptr)
		return;
	if (this->contains(node->value))
		s3->addString(node->value);
	recursiveIntersect(node->leftChild, s3);
	recursiveIntersect(node->rightChild, s3);
}

BSTSet::BSTSet(BSTSet &tree) {
	// DONE: Implement copy constructor for BST
	head = nullptr;
	set_size = 0;
	this->recursiveCopy(tree.head);
}

// Recursively traverses and destroys nodes bottom to top
void BSTSet::recursiveDestruction(const BSTSet::BSTNode *node) {
	if (node != nullptr) {
		recursiveDestruction(node->leftChild);
		recursiveDestruction(node->rightChild);
		delete node;
	}
}

BSTSet::~BSTSet() {
	// DONE: Implement Desctructor for BST
	recursiveDestruction(this->head);
}

// Add string to the set
void BSTSet::addString(const CustomString &s) {
	if (head == nullptr) {
		// std::cout << "head was null! setting new node with " << s
		// 		  << std::endl; // DEBUGGING:
		head = new BSTNode(s);
		// std::cout << "Successfully created newnode which contains "
		// 		  << head->value << std::endl; // DEBUGGING:
		// std::cout << "Finished setting head to new BSTNode!"
		// 		  << std::endl; // DEBUGGING

	} else {
		// std::cout << "somehow entered else!!" << std::endl; // DEBUGGING
		BSTNode *curNode = head;
		BSTNode *prevNode = head;

		while (curNode != nullptr) {
			prevNode = curNode;
			if (s == curNode->value) {
				// This is a set so no identical strings allowed
				std::cout
					<< colorText(s, "33")
					<< colorText(
						   " is already a string in this set! Nothing was "
						   "added.",
						   "33")
					<< std::endl;
				return;
			} else if (s < curNode->value) {
				curNode = curNode->leftChild;
			} else {
				curNode = curNode->rightChild;
			}
		}

		if (s < prevNode->value) {
			prevNode->leftChild = new BSTNode(s);
		} else {
			prevNode->rightChild = new BSTNode(s);
		}
	}
	set_size += 1;
}

CustomString printTree(BSTSet::BSTNode *head) {
	// std::cout << "now attempting to print tree" << std::endl; // DEBUGGING:
	if (head == nullptr)
		return "";
	return printTree(head->leftChild) + "\'" + colorText(head->value, "36") +
		   "\' " + printTree(head->rightChild);
}

// Allow a set to be printed with cout
std::ostream &operator<<(std::ostream &os, const BSTSet &set) {
	// DONE: Make String function with std::cout
	return os << "(BST Set of size " << set.set_size
			  << "): " << colorText("{", "33") << printTree(set.head)
			  << colorText("}", "33");
}

void BSTSet::clear() {
	this->~BSTSet();
	head = nullptr;
	set_size = 0;
}

void BSTSet::swap(BSTSet &s2) {
	BSTNode *temp = this->head;
	int size_temp = this->set_size;
	this->head = s2.head;
	this->set_size = s2.set_size;
	s2.head = temp;
	s2.set_size = size_temp;
}

// Helper function for binary search of BST
bool _contains(const CustomString &s, BSTSet::BSTNode *node) {
	if (node == nullptr)
		return false; // Empty node, does not contain
	if (s == node->value) {
		return true;
	} else if (s < node->value) {
		return _contains(s, node->leftChild);
	} else {
		return _contains(s, node->rightChild);
	}
}

// Binary searches this BST looking for string s
bool BSTSet::contains(const CustomString &s) const {
	if (this->head == nullptr)
		return false; // Empty node, does not contain
	if (s == head->value) {
		return true;
	} else if (s < head->value) {
		return _contains(s, head->leftChild);
	} else {
		return _contains(s, head->rightChild);
	}
}

// Iterates through S2 and sends to S1 for checking if contained
bool containedIn(BSTSet *s1, BSTSet::BSTNode *node) {
	if (node == nullptr)
		return true;
	return containedIn(s1, node->leftChild) && s1->contains(node->value) &&
		   containedIn(s1, node->rightChild);
}

bool BSTSet::isProperSubset(const BSTSet &s2) {
	if (this->set_size <= s2.set_size)
		return false; // S1 is not larger so S2 cannot possibly be proper subset

	return containedIn(this, s2.head);
}