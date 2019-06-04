#include "HuffmanTrie.h"

#include <iostream>
#include <fstream>

using namespace std;
int main() {
	string fullText = "", input = "", file;
	
	cout << "Enter file name: ";
	cin >> file;
	cout << endl;
	
	ifstream fin(file);
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, input);
			fullText += input;
		}
		fin.close();
	}
	else {
		cout << "Unable to open file" << endl;
		return 1;
	}
	
	cout << "ORIGINAL TEXT: " << endl << fullText << endl;
	
	cout << endl << "FREQUENCY TABLE: " << endl;
	HuffmanTrie t = HuffmanTrie(fullText);
	
	cout << endl << "CODE TABLE: " << endl;
	t.encode();
	
	cout << endl << "COMPRESSED STRING: " << endl;
	t.printCompressedString();
	
	cout << endl << "COMPRESSION RATIO: " << endl << t.getEfficiency() << "%" << endl;
	
	return 0;
}