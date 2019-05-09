//
// AVLTree.cpp
// Created by Panda on 5/8/19.

#include "AVLTree.h"
#include <iostream>
#include <string>

using namespace std;


void AVLTree::insert(const string &word) {
	Node* newNode = new Node(word);
	
	if (root == nullptr) {
		root = newNode;
		root->balanceNumber = -1;
		return;
	}
	
	Node* currNode = root;
	Node* parentNode = nullptr;
	
	while (currNode != nullptr) {
		parentNode = currNode;
		if (newNode->data < currNode->data) {
			currNode = currNode->left;
		}
		else if (newNode->data > currNode->data){
			currNode = currNode->right;
		}
		else {
			return;
		}
	}
	
	if (newNode->data < parentNode->data) {
		parentNode->left = newNode;
		newNode->parent = parentNode;
	}
	else {
		parentNode->right = newNode;
		newNode->parent = parentNode;
	}
	
	updateBalanceFactors(newNode);
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

void AVLTree::updateBalanceFactors(Node* node) {
	setBalanceFactors(root);
	while (findUnbalancedNode(node) != 0) {
		rotate(findUnbalancedNode(node));
		setBalanceFactors(root);
	}
}

void AVLTree::setBalanceFactors(Node* node) {
	if (node != nullptr) {
		node->balanceNumber = balanceFactor(node);
		setBalanceFactors(node->left);
		setBalanceFactors(node->right);
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