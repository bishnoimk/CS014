#include <iostream>

#include "IntList.h"

int main() {
	IntList test = IntList();
	
	test.push_back(6);
	test.push_back(7);
	test.push_back(8);
	test.push_front(5);
	
	cout << test << endl;
	test.printReverse();
	cout << endl;
	
	test.pop_back();
	test.pop_front();
	
	cout << test << endl;
	test.printReverse();
	cout << endl;
	
	test.pop_front();
	test.pop_back();
	
	cout << test << endl;
	test.printReverse();
	
	cout << "Empty: " << test.empty() << endl;
	return 0;
}