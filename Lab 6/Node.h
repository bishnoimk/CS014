//
// Node.h
// Created by Panda on 5/5/19.

#ifndef _Node_h_
#define _Node_h_

#include <string>

using namespace std;

class Node {
	public:
		Node(string);
		string data;
		Node* left;
		Node* right;
		Node* parent;
		int balanceNumber;
};

#endif