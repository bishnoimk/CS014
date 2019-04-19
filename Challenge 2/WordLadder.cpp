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
	while (fin >> currWord) {
		if (currWord.length() == 5) {
			dict.push_back(currWord);
		}
	}
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
	stack<string> wordStack;
	wordStack.push(start);
	
	queue<stack<string>> ladder;
	ladder.push(wordStack);
	
	while (!ladder.empty()) {
		for (auto i = dict.begin(); i != dict.end(); i++) {
			
		}
	}
}

bool diffByOne(string s1, string s2) {
	
}