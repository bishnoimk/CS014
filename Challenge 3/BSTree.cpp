#include "BSTree.h"
#include <string>
#include <iostream>

using namespace std;

void BSTree::insert(const string &data) {
	Node* newNode = new Node(data);
	if (root == nullptr) {
		root = newNode;
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
			currNode->count += 1;
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
}

bool BSTree::search(const string &data) const {
	return searchNode(data) != nullptr;
}

Node* BSTree::searchNode(string data) const {
	Node* currNode = root;
	while (currNode != nullptr) {
		if (currNode->data == data) {
			return currNode;
		}
		
		if (currNode->data < data) {
			currNode = currNode->right;
		}
		else {
			currNode = currNode->left;
		}
	}
	return nullptr;
}

void BSTree::inOrder() const {
	inOrder(root);
}

void BSTree::inOrder(Node* node) const {
	if (node != nullptr) {
		inOrder(node->left);
		cout << node->data << "(" << node->count << "), ";
		inOrder(node->right);
	}
	else {
		return;
	}
}

void BSTree::preOrder() const {
	preOrder(root);
}

void BSTree::preOrder(Node* node) const {
	if (node != nullptr) {
		cout << node->data << "(" << node->count << "), ";
		preOrder(node->left);
		preOrder(node->right);
	}
	else {
		return;
	}
}

void BSTree::postOrder() const {
	postOrder(root);
}

void BSTree::postOrder(Node* node) const {
	if (node != nullptr) {
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << "(" << node->count << "), ";
	}
	else {
		return;
	}
}

string BSTree::largest() const {
	string largest = "";
	if (root != nullptr) {
		Node* currNode = root;
		while (currNode->right != nullptr) {
			currNode = currNode->right;
		}
		largest = currNode->data;
	}
	return largest;
}

string BSTree::smallest() const {
	string smallest = "";
	if (root != nullptr) {
		Node* currNode = root;
		while (currNode->left != nullptr) {
			currNode = currNode->left;
		}
		smallest = currNode->data;
	}
	return smallest;
}

int BSTree::getHeight(Node* node) const {
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

int BSTree::height(const string &data) const {
	Node* rootNode = searchNode(data);
	
	if (rootNode == nullptr) {
		return -1;
	}
	
	if (rootNode->left == nullptr && rootNode->right == nullptr) {
		return 0;
	}
	
	return getHeight(rootNode);
}

void BSTree::remove(const string &data) {
	Node* searchedNode = searchNode(data);
	
	if (root == nullptr) {
		return;
	}
	
	if (searchedNode == nullptr) {
		return;
	}
	
	if (searchedNode->count > 1) {
		searchedNode->count -= 1;
		return;
	}
	
	removeNode(searchedNode, data);
}

void BSTree::removeNode(Node* node, string data) {
	 Node* parentNode = node->parent;
	
	if (node->left == nullptr && node->right == nullptr) {
		if (parentNode == nullptr) {
			root = nullptr;
		}
		else if (parentNode->left == node) {
			parentNode->left = nullptr;
		}
		else {
			parentNode->right = nullptr;
		}
		delete node;
		return;
	}
	else if (node->left == nullptr) {
		Node* successor = findSuccessor(node);
		node->data = successor->data;
		node->count = successor->count;
		if (successor->count > 1) {
			successor->count -= 1;
		}
		removeNode(successor, successor->data);
		return;
	}
	else {
		Node* predecessor = findPredecessor(node);
		node->data = predecessor->data;
		node->count = predecessor->count;
		if (predecessor->count > 1) {
			predecessor->count -= 1;
		}
		removeNode(predecessor, predecessor->data);
		return;
	}
}

Node* BSTree::findSuccessor(Node* node) const {
	if (node->right != nullptr) {
		Node* currNode = node->right;
		while (currNode->left != nullptr) {
			currNode = currNode->left;
		}
		return currNode;
	}
	return nullptr;
}

Node* BSTree::findPredecessor(Node* node) const {
	if (node->left != nullptr) {
		Node* currNode = node->left;
		while (currNode->right != nullptr) {
			currNode = currNode->right;
		}
		return currNode;
	}
	return nullptr;
}