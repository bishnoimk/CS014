//
// HuffmanTrie.cpp
// Created by Panda on 5/28/19.

#include "HuffmanTrie.h"

HuffmanTrie::HuffmanTrie(string str) {
	efficiency = 0;
	root = nullptr;
	encodeString = str;
	compressedString = "";
	
	for (char ch: str) {
		frequencyTable[ch] += 1;
	}
	
	for (auto i = frequencyTable.begin(); i != frequencyTable.end(); i++) {
		cout << i->first << " " << i->second << endl;
	}
	
	priority_queue<Node*, vector<Node*>, Compare> priorityQueue;
	
	for (auto i = frequencyTable.begin(); i != frequencyTable.end(); i++) {
		Node* node = new Node(i->first, i->second);
		leafNodes[i->first] = node;
		priorityQueue.push(node);
	}
	
	while (priorityQueue.size() > 1) {
		Node* leftNode = priorityQueue.top();
		priorityQueue.pop();
		
		Node* rightNode = priorityQueue.top();
		priorityQueue.pop();
		
		Node* parent = new Node(' ', leftNode->count + rightNode->count);
		parent->left = leftNode;
		parent->right = rightNode;
		leftNode->parent = parent;
		rightNode->parent = parent;
		priorityQueue.push(parent);
	}
	
//	while (!priorityQueue.empty()) {
//		cout << priorityQueue.top()->character << priorityQueue.top()->count << endl;
//		priorityQueue.pop();
//	}
	
	root = priorityQueue.top();
	priorityQueue.pop();
}

string HuffmanTrie::encode(char c) {
	string code = "";
	Node* currNode = leafNodes[c];
	while (currNode->parent != nullptr) {
		if (currNode == currNode->parent->left) {
			code += "0";
		}
		else if (currNode == currNode->parent->right) {
			code += "1";
		}
		currNode = currNode->parent;
	}
	reverse(code.begin(), code.end());
	return code;
}

void HuffmanTrie::encode() {
	for (int i = 0; i < encodeString.length(); i++) {
		string currCode = encode(encodeString[i]);
		binaryTable[encodeString[i]] = currCode;
		compressedString += currCode;
	}
	
	for (auto i = binaryTable.begin(); i != binaryTable.end(); i++) {
		cout << i->first << " " << i->second << " " << endl;
	}
}

void HuffmanTrie::printCompressedString() {
	cout << compressedString << endl;
}

double HuffmanTrie::getEfficiency() {
	double bytes = 0;
	for (auto i = frequencyTable.begin(); i != frequencyTable.end(); i++) {
		bytes += (i->second * binaryTable[i->first].length());
	}
	bytes /= 8;
	double initialSize = encodeString.length();
	return (1 - (bytes / initialSize)) * 100;
}
