//
// AVLTree.h
// Created by Panda on 5/8/19.

#ifndef _AVLTree_h_
#define _AVLTree_h_

#include "Node.h"

#include <string>
#include <fstream>

using namespace std;

class AVLTree {
	private:
		Node* root;
		Node* findUnbalancedNode(Node*);
		Node* rotateLeft(Node*);
		Node* rotateRight(Node*);
		void printBalanceFactors(Node*);
		void visualizeTree(ofstream&, Node*);
		void rebalance(Node*);
		void setBalanceFactors(Node*);
		int getHeight(Node*) const;
	public:
		AVLTree() {
			root = nullptr;
		}
		void insert(const string &);
		int balanceFactor(Node*);
		void printBalanceFactors();
		void visualizeTree(const string &);
};

#endif