//
// Node.cpp
// Created by Panda on 5/5/19.

#include "Node.h"
#include <string>

using namespace std;

Node::Node(string dat) {
	data = dat;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	count = 1;
}