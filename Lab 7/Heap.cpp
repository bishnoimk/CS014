//
// Heap.cpp
// Created by Panda on 5/13/19.

#include "Heap.h"

using namespace std;

Heap::Heap() {
	numItems = 0;
}

void Heap::enqueue(PrintJob* job) {
	if (numItems < MAX_HEAP_SIZE) {
		if (numItems == 0) {
			arr[numItems] = job;
			numItems += 1;
		}
		else {
			int index = numItems;
			while (index > 0 && arr[(index - 1) / 2]->getPriority() < job->getPriority()) {
				arr[index] = arr[(index - 1) / 2];
				index = (index - 1) / 2;
			}
			arr[index] = job;
			numItems += 1;
		}
	}
}

void Heap::trickleDown(int index) {
	if ((index * 2 + 1) < numItems) {
		if ((index * 2 + 2) < numItems) {
			if (arr[index * 2 + 1]->getPriority() > arr[index * 2 + 2]->getPriority()) {
				arr[index] = arr[index * 2 + 1];
				trickleDown(index * 2 + 1);
			}
			else {
				arr[index] = arr[index * 2 + 2];
				trickleDown(index * 2 + 2);
			}
		}
		else {
			arr[index] = arr[index * 2 + 1];
		}
	}
}

void Heap::dequeue() {
	if (numItems > 2) {
		if (arr[1]->getPriority() < arr[numItems - 1]->getPriority() && arr[2]->getPriority() < arr[numItems - 1]->getPriority()) {
			arr[0] = arr[numItems - 1];
			numItems -= 1;
		}
		else {
			trickleDown(0);
			numItems -= 1;
		}
	}
	else {
		trickleDown(0);
		numItems -= 1;
	}
}

PrintJob* Heap::highest() {
	if (numItems > 0) {
		return arr[0];
	}
	else {
		return 0;
	}
}

void Heap::print() {
	if (numItems > 0) {
		cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;	
	}
	else {
		cout << "The heap is empty." << endl;
	}
}