//
// AVLTree.cpp
// Created by Panda on 5/8/19.

#include "AVLTree.h"
#include <iostream>
#include <string>

using namespace std;


void AVLTree::insert(const string &word) {
	Node* newNode = new Node(word);
	
	Node* currNode = root;
	Node* parentNode = nullptr;
	
	if (root == nullptr) {
		root = newNode;
		root->balanceFactor = -1;
		return;
	}
	
	while (currNode != nullptr) {
		parentNode = currNode;
		if (newNode->data == parentNode->data) {
			return;
		}
		
		if (newNode->data < parentNode->data) {
			currNode = currNode->left;
		}
		
		if (newNode->data >= parentNode->data){
			currNode = currNode->right;
		}
	}
	
	if (newNode->data < parentNode->data) {
		parentNode->left = newNode;
		newNode->parent = parentNode;
	}
	else if (newNode->data > parentNode->data) {
		parentNode->right = newNode;
		newNode->parent = parentNode;
	}

	setBalanceFactors(root);
	rebalance(newNode);
}

int AVLTree::balanceFactor(Node* node) {
	int leftHeight = 0, rightHeight = 0;
	if (node == nullptr) {
		return -1;
	}
	
	if (node->left) {
		leftHeight = getHeight(node->left);
	}
	else {
		leftHeight = -1;
	}
	
	if (node->right) {
		rightHeight = getHeight(node->right);
	}
	else {
		rightHeight = -1;
	}
	
	return leftHeight - rightHeight;
}

void AVLTree::setBalanceFactors(Node* node) {
	if (node != nullptr) {
		node->balanceFactor = balanceFactor(node);
		setBalanceFactors(node->left);
		setBalanceFactors(node->right);
	}
}

Node* AVLTree::rotateLeft(Node* node) {
	Node* parent = node->parent;
	Node* child = node->right;
	Node* grandChild = child->left;
	
	if (parent == nullptr) {
		root = child;
	}
	else {
		if (parent->data > node->data) {
			parent->left = child;
		}
		else if (parent->data < node->data){
			parent->right = child;
		}
	}
	
	child->left = node;
	node->right = grandChild;
	child->parent = node->parent;
	node->parent = child;
	
	return child;
}

Node* AVLTree::rotateRight(Node* node) {
	Node* parent = node->parent;
	Node* child = node->left;
	Node* grandChild = child->right;
	
	if (parent == nullptr) {
		root = child;
	}
	else {
		if (parent->data > node->data) {
			parent->left = child;
		}
		else if (parent->data < node->data){
			parent->right = child;
		}
	}
	
	child->right = node;
	node->left = grandChild;
	child->parent = node->parent;
	node->parent = child;
	
	return child;
}

Node* AVLTree::findUnbalancedNode(Node* node) {
	Node* currNode = node;
	while (currNode != nullptr) {
		if (balanceFactor(currNode) >= 2 || balanceFactor(currNode) <= -2) {
			return currNode;
		}
		else {
			currNode = currNode->parent;
		}
	}
	return nullptr;
}

void AVLTree::rebalance(Node* node) {
	while (findUnbalancedNode(node) != 0) {
		Node* unbalancedNode = findUnbalancedNode(node);
		int bf = balanceFactor(unbalancedNode);
		int bfLeft = balanceFactor(unbalancedNode->left);
		int bfRight = balanceFactor(unbalancedNode->right);
		
		if (bf == -2 && bfLeft == -1) {
			rotateLeft(unbalancedNode);
		}
		else if (bf == 2 && bfLeft == -1) {
			rotateLeft(unbalancedNode->left);
			rotateRight(unbalancedNode);
		}
		else if (bf == 2 && bfRight == 1 ){
			rotateRight(unbalancedNode);
		}
		else {
			rotateRight(unbalancedNode->right);
			rotateLeft(unbalancedNode);
		}
		setBalanceFactors(root);
	}
}

void AVLTree::printBalanceFactors() {
	rebalance(root);
	printBalanceFactors(root);
	cout << endl;
}

void AVLTree::printBalanceFactors(Node* node) {
	if (node != nullptr) {
		printBalanceFactors(node->left);
		cout << node->data << "(" << balanceFactor(node) << "), ";
		printBalanceFactors(node->right);
	}
}

void AVLTree::visualizeTree(const string &outputFilename){
	ofstream outFS(outputFilename.c_str());
	if(!outFS.is_open()){
		cout<<"Error"<<endl;
		return;
	}
	outFS<<"digraph G {"<<endl;
	visualizeTree(outFS,root);
	outFS<<"}";
	outFS.close();
	string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
	string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
	system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
	if(n){
		if(n->left){
			visualizeTree(outFS,n->left);
			outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
		}

		if(n->right){
			visualizeTree(outFS,n->right);
			outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
		}
	}
}

int AVLTree::getHeight(Node* node) const {
	if (node == nullptr) {
		return -1;
	}
	else if (node->left == nullptr && node->right == nullptr) {
		return 0;
	}
	
	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);
	
	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	}
	else {
		return rightHeight + 1;
	}
	
	return 0;
}