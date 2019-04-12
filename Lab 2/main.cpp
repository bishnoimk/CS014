#include <iostream>

#include "IntList.h"

int main() {
	IntList test = IntList();
	
	cout << "Adding values..." << endl;
	test.push_back(6);
	test.push_back(7);
	test.push_back(8);
	test.push_front(5);
	
	cout << "List: " << test << endl;
	cout << "Reversed list: ";
	test.printReverse();
	cout << endl;
	
	cout << "Removing first and last values..." << endl;
	test.pop_back();
	test.pop_front();
	
	cout << "List: " << test << endl;
	cout << "Reversed list: ";
	test.printReverse();
	cout << endl;
	
	cout << "Removing remaining values..." << endl;
	test.pop_front();
	test.pop_back();
	
	cout << "Printing empty list..." << endl;
	cout << test << endl;
	test.printReverse();
	
	cout << "Print 1 if empty: " << test.empty() << endl;
	return 0;
}