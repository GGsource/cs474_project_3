#include "BSTNode.h"
#include <iostream>

// Tree node definition
BSTNode::BSTNode(String val) : value(val) {
	std::cout << "Entered BSTNode constructor!" << std::endl; // DEBUGGING:
	leftChild = nullptr;
	rightChild = nullptr;
	std::cout << "Successfully got through BSTNode constructor!"
			  << std::endl; // DEBUGGING:
}