#include "BSTSet.h"
#include <iostream>
#include <ostream>

BSTSet::BSTNode::BSTNode(String val) : value(val) {
	std::cout << "Entered BSTNode constructor!" << std::endl; // DEBUGGING:
	leftChild = nullptr;
	rightChild = nullptr;
	std::cout << "Successfully got through BSTNode constructor!"
			  << std::endl; // DEBUGGING:
}

BSTSet::BSTSet() {
	head = nullptr;
	set_size = 0;
}

BSTSet::BSTSet(BSTSet &tree) {
	// TODO: Implement copy constructor for BST
	// traverse n copy
	// copy set_size
	std::cout << "BSTSet copy constructor called but not yet implemented..."
			  << std::endl;
}

BSTSet::~BSTSet() {
	// TODO: Implement Desctructor for BST
	// traverse n destroy
	std::cout << "BSTSet destructor called but not yet implemented..."
			  << std::endl;
}

// Add string to the set
void BSTSet::addString(const String &s) {
	if (head == nullptr) {
		std::cout << "head was null! setting new node with " << s
				  << std::endl; // DEBUGGING:
		head = new BSTNode(s);
		std::cout << "Successfully created newnode which contains "
				  << head->value << std::endl; // DEBUGGING:
		std::cout << "Finished setting head to new BSTNode!"
				  << std::endl; // DEBUGGING

	} else {
		std::cout << "somehow entered else!!" << std::endl; // DEBUGGING
		BSTNode *curNode = head;
		BSTNode *prevNode = head;

		while (curNode != nullptr) {
			prevNode = curNode;
			if (s == curNode->value) {
				// This is a set so no identical strings allowed
				std::cout
					<< s
					<< " is already a string in this set! Nothing was added"
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

String printTree(BSTSet::BSTNode *head) {
	// std::cout << "now attempting to print tree" << std::endl; // DEBUGGING:
	if (head == nullptr)
		return String("");
	return printTree(head->leftChild) + head->value +
		   printTree(head->rightChild);
}

// Allow a set to be printed with cout
std::ostream &operator<<(std::ostream &os, const BSTSet &set) {
	// DONE: Make String function with std::cout
	return os << "(BST Set of size " << set.set_size << "): ["
			  << printTree(set.head) << "]";
}