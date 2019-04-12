#include <iostream>

#include "JosephusCircle.h"

using namespace std;

int main() {
	JosephusCircle list = JosephusCircle();
	string fileName;
	int numContestants, startIndex, skip;
	cout << "Number of contestants: ";
	cin >> numContestants;
	cout << "Starting position: ";
	cin >> startIndex;
	cout << "Number to skip: ";
	cin >> skip;
	cout << "Enter file name: ";
	cin >> fileName;
	list.josephus(numContestants, fileName, startIndex, skip);
}