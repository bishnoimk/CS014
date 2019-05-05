#include <iostream>

#include "WordLadder.h"

using namespace std;

int main() {
	string word1, word2, ofile;
	WordLadder l = WordLadder("dictionary");
	cout << "First word: ";
	cin >> word1;
	cout << "Second word: ";
	cin >> word2;
	cout << "Output file: ";
	cin >> ofile;
	l.outputLadder(word1, word2, ofile);
	return 0;
}