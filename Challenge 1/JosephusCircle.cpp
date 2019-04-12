#include <iostream>
#include <fstream>

#include "JosephusCircle.h"

using namespace std;

Contestant::Contestant(string n) {
	name = n;
	next = nullptr;
}

JosephusCircle::JosephusCircle() {
	head = nullptr;
	tail = nullptr;
	josephusActivated = false;
}

void JosephusCircle::add(string name) {
	Contestant* newEntry = new Contestant(name);
	if (head == nullptr) {
		head = newEntry;
		tail = newEntry;
		head->next = tail;
		tail->next = head;
	}
	else {
		tail->next = newEntry;
		tail = newEntry;
		newEntry->next = head;
	}
}

void JosephusCircle::josephus(int n, string file, int start, int k) {
	josephusActivated = true;
	ifstream fin;
	fin.open(file);
	string input, title;
	int i = 0;
	while (fin >> input && i < n) {
		add(input);
		i += 1;
	}
	
	if (head->next != head) {
		Contestant* curr = head;
		Contestant* prev = tail;
		
		i = 1;
		while (i < start) {
			prev = curr;
			curr = curr->next;
			i += 1;
		}
		
		while (curr->next != curr) {
			int kcount = 0;
			
			while (kcount != k) {
				prev = curr;
				curr = curr->next;
				kcount += 1;
			}
			
			title = curr->name;
			prev->next = curr->next;
			cout << title << " was eliminated! 💀" << endl;
			delete curr;
			curr = prev->next;
		}
		delete curr;
		cout << curr->name << " wins! 😈" << endl;
	}
}