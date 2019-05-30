#include "Node.h"

using namespace std;

Node::Node(char data, int frequency) {
	character = data;
	count = frequency;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}