#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
	unsigned minValue = index;
	for (unsigned int i = index; i < vals.size(); i++) {
		if (vals.at(i) < vals.at(minValue)) {
			minValue = i;
		}
	}
	return minValue;
}

template <typename T>
void selection_sort(vector<T> &vals) {
	for (unsigned int i = 0; i < vals.size(); i++) {
		unsigned int min = i;
		for (unsigned int j = i + 1; j < vals.size(); j++) {
			if (vals.at(j) < vals.at(min)) {
				min = j;
			}
		}
		if (min != i) {
			swap(vals.at(min), vals.at(i));
		}
	}
}

template <typename T>
T getElement(vector<T> vals, int index) {
	T value;
	try {
		value = vals.at(index);
	} catch (out_of_range& oor) {
		cerr << "Out of range error: " << oor.what() << endl; 
	}
	return value;
}

vector<char> createVector(){
	int vecSize = rand() % 26;
	char c = 'a';
	vector<char> vals;
	for(int i = 0; i < vecSize; i++)
	{
		vals.push_back(c);
		c++;
	}
	return vals;
}

int main() {
	//Part A
	cout << "PART A" << endl;
	srand(time(nullptr));
	
	cout << "INTEGER VECTOR: ";
	vector<int> intVector;
	for (int i = 0; i < 10; i++) {
		intVector.push_back(rand() % 10 + 1);
		cout << intVector.at(i) << " ";
	}
	cout << endl;
	cout << "Smallest int value: " << min_index(intVector, 0) << endl;
	cout << "Running selection sort..." << endl;
	selection_sort(intVector);
	cout << "New integer vector: ";
	for (int i = 0; i < 10; i++) {
		cout << intVector.at(i) << " ";
	}
	cout << endl;
	
	cout << endl;
	
	cout << "STRING VECTOR: ";
	vector<string> stringVector = {"The", "Quick", "Brown", "Fox", "Jumps", "Over", "The", "Lazy", "Dog", "."};
	cout << endl;
	cout << "Smallest string: " << min_index(stringVector, 0) << endl;
	cout << "Running selection sort..." << endl;
	selection_sort(stringVector);
	cout << "New string vector: ";
	for (int i = 0; i < 10; i++) {
		cout << stringVector.at(i) << " ";
	}
	cout << endl << endl;
	
	//Part B
	cout << "PART B" << endl;
	srand(time(0));
	vector<char> vals = createVector();
	char curChar;
	int index;
	int numOfRuns = 10;
	while(--numOfRuns >= 0){
		cout << "Enter a number: " << endl;
		cin >> index;
		curChar = getElement(vals,index);
		cout << "Element located at " << index << ": is " << curChar << endl;
	}
	return 0;
}