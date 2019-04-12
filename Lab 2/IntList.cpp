#include <iostream>

#include "IntList.h"

using namespace std;

IntList::IntList() {
	dummyHead = new IntNode(0);
	dummyTail = new IntNode(0);
}

IntList::~IntList() {
	IntNode* currNode = dummyHead;
	while (currNode != nullptr) {
		IntNode* temp = currNode->next;
		delete currNode;
		currNode = temp;
	}
}

void IntList::push_front(int value) {
	IntNode* newNode = new IntNode(value);
	if (dummyHead->next == nullptr) {
		dummyHead->next = newNode;
		dummyTail->prev = newNode;
		newNode->next = dummyTail;
		newNode->prev = dummyHead;
	}
	else {
		IntNode* temp = dummyHead->next;
		newNode->next = temp;
		dummyHead->next = newNode;
		newNode->prev = dummyHead;
		temp->prev = newNode;
	}
}

void IntList::pop_front() {
	if (dummyHead->next != nullptr) {
		if (dummyHead->next->next != dummyTail) {
			IntNode* currNode = dummyHead->next->next;
			delete dummyHead->next;
			dummyHead->next = currNode;
			currNode->prev = dummyHead;
			
		}
		else {
			delete dummyHead->next;
			dummyHead->next = nullptr;
			dummyTail->prev = nullptr;
		}
	}
}

void IntList::push_back(int value) {
	IntNode* newNode = new IntNode(value);
	if (dummyHead->next == nullptr) {
		dummyHead->next = newNode;
		dummyTail->prev = newNode;
		newNode->next = dummyTail;
		newNode->prev = dummyHead;
	}
	else {
		IntNode* temp = dummyTail->prev;
		dummyTail->prev = newNode;
		newNode->next = dummyTail;
		newNode->prev = temp;
		temp->next = newNode;
	}
}

void IntList::pop_back() {
	if (dummyHead->next != nullptr) {
		if (dummyTail->prev->prev != dummyHead) {
			IntNode* currNode = dummyTail->prev->prev;
			delete dummyTail->prev;
			dummyTail->prev = currNode;
			currNode->next = dummyTail;
		}
		else {
			delete dummyHead->next;
			dummyHead->next = nullptr;
			dummyTail->prev = nullptr;
		}
	}
}

bool IntList::empty() const {
	return dummyHead->next == nullptr;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
	if (rhs.dummyHead->next != nullptr) {
		IntNode* currNode = rhs.dummyHead->next;
		while (currNode != rhs.dummyTail) {
			if(currNode != rhs.dummyTail->prev) {
				out << currNode->data << " ";
			}
			else {
				out << currNode->data;
			}
			currNode = currNode->next;
		}
	}
	return out;
}

void IntList::printReverse() const {
	if (dummyHead->next != nullptr) {
		IntNode* currNode = dummyTail->prev;
		while (currNode != dummyHead) {
			if (currNode == dummyHead->next) {
				cout << currNode->data;
			}
			else {
				cout << currNode->data << " ";
			}
			currNode = currNode->prev;
		}
	}
}