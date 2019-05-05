//
// WordLadder.cpp
// Created by Panda on 4/18/19.

#include "WordLadder.h"

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

WordLadder::WordLadder(const string &fileName) {
	ifstream fin(fileName);
	string currWord;
	if (!fin.is_open()) {
		cout << "Unable to open file." << endl;
		exit(0);
	}
	while (fin >> currWord) {
		if (currWord.length() == 5) {
			dict.push_back(currWord);
		}
	}
	fin.close();
}

bool wordDiff(string s1, string s2) {
	int diffCount = 0;
	int sz = s1.length();
	for (int i = 0; i < sz; i++) {
		if (s1[i] != s2[i]) {
			diffCount += 1;
			if (diffCount > 1) {
				return false;
			}
		}
	}
	return diffCount == 1;
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
	stack<string> wordStack;
	wordStack.push(start);
	
	queue<stack<string>> ladder;
	ladder.push(wordStack);
	
	if (start == end) {
		exit(0);
	}
	
	while (!ladder.empty() && !dict.empty()) {
		for (auto i = dict.begin(); i != dict.end(); i++) {
			if (wordDiff(*i, ladder.front().top())) {
				if (*i == end) {
					stack<string> endStack;
					endStack.push(*i);
					while (ladder.front().empty() == false) {
						endStack.push(ladder.front().top());
						ladder.front().pop();
					}
					ofstream fout(outputFile);
					if (endStack.empty() == false) {
						if (!fout.is_open()) {
							cout << "Invalid file name." << endl;
							exit(1);
						}
						while (endStack.empty() == false) {
							fout << endStack.top() << endl;
							endStack.pop();
						}
						fout.close();
					}
					else {
						cout << "No Word Ladder found." << endl;
						exit(0);
					}
					exit(0);
				}
				else {
					stack<string> newStack = ladder.front();
					newStack.push(*i);
					ladder.push(newStack);
					i = dict.erase(i);
					i--;
				}
			}
		}
		ladder.pop();
	}
}