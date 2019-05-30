#ifndef _Node_h_
#define _Node_h_

#include <iostream>

using namespace std;

class Node {
	public:
		Node(char, int);
		int count;
		char character;
		Node* left;
		Node* right;
		Node* parent;
};

#endif