#include "BSTSet.h"
#include <iostream>
#include <ostream>

BSTSet::BSTNode::BSTNode(CustomString val) : value(val) {
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
	std::cout << "called BSTSet copy constructor but not yet implemented..."
			  << std::endl;
}
void BSTSet::recursiveDestruction(const BSTSet::BSTNode *node) {
	if (node != nullptr) {
		recursiveDestruction(node->leftChild);
		recursiveDestruction(node->rightChild);
		delete node;
	}
}

BSTSet::~BSTSet() {
	// TODO: Implement Desctructor for BST
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
				std::cout << s
						  << " is already a string in this set! Nothing was "
							 "added" // TODO: Make this be yellow
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
	return printTree(head->leftChild) + "\'" + head->value + "\' " +
		   printTree(head->rightChild);
}

// Allow a set to be printed with cout
std::ostream &operator<<(std::ostream &os, const BSTSet &set) {
	// DONE: Make String function with std::cout
	return os << "(BST Set of size " << set.set_size << "): ["
			  << printTree(set.head) << "]";
}

void BSTSet::clear() {
	recursiveDestruction(this->head);
	// std::cout << "successfully destroyed to clear " << std::endl;
	head = nullptr;
	set_size = 0;
}

void BSTSet::swap(BSTSet &s2) {
	BSTNode *temp = this->head;
	this->head = s2.head;
	s2.head = temp;
}