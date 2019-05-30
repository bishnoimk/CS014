//
// HuffmanTrie.h
// Created by Panda on 5/28/19.

#ifndef _HuffmanTrie_h_
#define _HuffmanTrie_h_

#include "Node.h"

#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <string>
#include <vector>

using namespace std;

struct Compare {
	bool operator()(const Node* first, const Node* second) const {
		return (first->count) > (second->count);
	}
};

class HuffmanTrie {
	private:
		map<char, int> frequencyTable;
		map<char, string> binaryTable;
		map<char, Node*> leafNodes;
		double efficiency;
		Node* root;
		string encodeString;
		string compressedString;
		string encode(char);
	public:
		HuffmanTrie(string);
		void encode();
		void printCompressedString();
		double getEfficiency();
};

#endif