//
// arithmeticexpression.cpp
// Created by Panda on 4/30/19.

#include <stack>
#include <string>
#include <sstream>
#include <fstream>

#include "arithmeticExpression.h"

using namespace std;

arithmeticExpression::arithmeticExpression(const string &str) {
	infixExpression = str;
	root = nullptr;
}

void arithmeticExpression::buildTree() {
	string postFix = infix_to_postfix();
	stack<TreeNode*> stac;
	TreeNode* currNode, *node1, *node2;
	char currChar;
	char key = 'a';
	
	for (unsigned int i = 0; i < postFix.length(); i++, key++){
		currChar = postFix[i];
		currNode = new TreeNode(currChar, key);
		if (priority(currChar) != 0) {
			node2 = stac.top();
			stac.pop();
			node1 = stac.top();
			stac.pop();
			currNode->left = node1;
			currNode->right = node2;
		}
		stac.push(currNode);
	}
	
	root = stac.top();
}

void arithmeticExpression::infix() {
	infix(root);
}

void arithmeticExpression::infix(TreeNode* node) {
	if (node != nullptr) {
		if (node->left != nullptr) {
			cout << '(';
		}
		infix(node->left);
		cout << node->data;
		infix(node->right);
		if (node->right != nullptr) {
			cout << ')';
		}
	}
}

void arithmeticExpression::prefix() {
	prefix(root);
}

void arithmeticExpression::prefix(TreeNode* node) {
	if (node != nullptr) {
		cout << node->data;
		prefix(node->left);
		prefix(node->right);
	}
}

void arithmeticExpression::postfix() {
	postfix(root);
}

void arithmeticExpression::postfix(TreeNode* node) {
	if (node != nullptr) {
		postfix(node->left);
		postfix(node->right);
		cout << node->data;
	}
}

int arithmeticExpression::priority(char op){
	int priority = 0;
	if(op == '('){
		priority =  3;
	}
	else if(op == '*' || op == '/'){
		priority = 2;
	}
	else if(op == '+' || op == '-'){
		priority = 1;
	}
	return priority;
}

string arithmeticExpression::infix_to_postfix(){
	stack<char> s;
	ostringstream oss;
	char c;
	for(unsigned i = 0; i< infixExpression.size();++i){
		c = infixExpression.at(i);
		if(c == ' '){
			continue;
		}
		if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
			if( c == '('){
				s.push(c);
			}
			else if(c == ')'){
				while(s.top() != '('){
					oss << s.top();
					s.pop();
				}
				s.pop();
			}
			else{
				while(!s.empty() && priority(c) <= priority(s.top())){
					if(s.top() == '('){
						break;
					}
					oss << s.top();
					s.pop();
				}
				s.push(c);
			}
		}
		else{ //c is an operand
			oss << c;
		}
	}
	while(!s.empty()){
		oss << s.top();
		s.pop();
	}
	return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
	ofstream outFS(outputFilename.c_str());
	if(!outFS.is_open()){
		cout<<"Error opening "<< outputFilename<<endl;
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

void arithmeticExpression::visualizeTree(ofstream &fout, TreeNode* node) {
	if (node != nullptr) {
		if (node->left != nullptr) {
			fout << node->key << " [ label = " << "\"" << node->data << "\"" << "];" << endl;
			fout << node->left->key << " [ label = " << "\"" << node->left->data << "\"" << "];" << endl;
			fout << node->key << " -> " << node->left->key << endl;
			if (node->right != nullptr) {
				fout << node->right->key << " [ label = " << "\"" << node->right->data << "\"" << "];" << endl;
				fout << node->key << " -> " << node->right->key << endl;
				visualizeTree(fout, node->left);
				visualizeTree(fout, node->right);
			}
			else {
				visualizeTree(fout, node->left);
			}
		}
		else {
			if (node->right != nullptr) {
				fout << node->key << " [ label = " << "\"" << node->data << "\"" << "];" << endl;
				fout << node->right->key << " [ label = " << "\"" << node->right->data << "\"" << "];" << endl;
				fout << node->key << " -> " << node->right->key << endl;
				visualizeTree(fout, node->right);
			}
		}
	}
}