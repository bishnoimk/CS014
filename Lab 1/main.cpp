/*
Collaborated with: Mayur Ryali
*/

#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

void PrintMenu(string title) {
	cout << title << " PLAYLIST MENU" << endl;
	cout << "a - Add song" << endl;
	cout << "d - Remove song" << endl;
	cout << "c - Change position of song" << endl;
	cout << "s - Output songs by specific artist" << endl;
	cout << "t - Output total time of playlist (in seconds)" << endl;
	cout << "o - Output full playlist" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
	cout << "Choose an option:" << endl;
}

void AddSong(PlaylistNode* &head, PlaylistNode* &tail) {
	string id, artist, title;
	int length;
	
	cout << "ADD SONG" << endl;
	cout << "Enter song's unique ID:" << endl;
	getline(cin, id);
	cout << "Enter song's name:" << endl;
	getline(cin, title);
	cout << "Enter artist's name:" << endl;
	getline(cin, artist);
	cout << "Enter song's length (in seconds):" << endl;
	if (cin >> length) {
		PlaylistNode* newSong = new PlaylistNode(id, title, artist, length);
		
		if (head == nullptr) {
			head = newSong;
			tail = newSong;
		}
		else {
			tail->SetNext(newSong);
			tail = newSong;
		}
	}
	else {
		cout << "Invalid integer inputted" << endl;
		cin.clear();
		cin.ignore();
	}
}

void RemoveSong(PlaylistNode* &head, PlaylistNode* &tail) {
	string id, title;
	
	if (head != nullptr) {
		cout << "REMOVE SONG" << endl;
		cout << "Enter song's unique ID:" << endl;
		getline(cin, id);
		
		PlaylistNode* temp = head;
		if (temp->GetID() == id) {
			title = temp->GetSongName();
			head = temp->GetNext();
			delete temp;
		}
		else {
			PlaylistNode* prev = nullptr;
			temp = head;
			while (temp->GetNext() != nullptr && temp->GetID() != id) {
				prev = temp;
				temp = temp->GetNext();
			}
			
			if (temp == tail) {
				tail = prev;
				prev->SetNext(nullptr);
				title = temp->GetSongName();
				delete temp;
			}
			else {
				prev->SetNext(temp->GetNext());
				title = temp->GetSongName();
				delete temp;
			}
		}
		cout << "\"" << title << "\"" << " removed" << endl;
	}
	else {
		cout << "Playlist is empty" << endl;
	}
}

void ChangePosition(PlaylistNode* &head, PlaylistNode* &tail) {
	int currPosition, newPosition;
	
	cout << "CHANGE POSITION OF SONG" << endl;
	cout << "Enter current position of song:" << endl;
	cin >> currPosition;
	cout << "Enter new position of song:" << endl;
	cin >> newPosition;
	
	if (currPosition != newPosition && head->GetNext() != nullptr) {
		int i = 1;
		PlaylistNode* prevNode = nullptr;
		PlaylistNode* currNode = head;
		while (i < currPosition && currNode->GetNext() != nullptr) {
			prevNode = currNode;
			currNode = currNode->GetNext();
			i += 1;
		}
		
		i = 1;
		PlaylistNode* tempPrevNode = nullptr;
		PlaylistNode* tempCurrNode = head;
		while (i < newPosition && tempCurrNode->GetNext() != nullptr) {
			tempPrevNode = tempCurrNode;
			tempCurrNode = tempCurrNode->GetNext();
			i += 1;
		}
		
		if (tempCurrNode != nullptr && currNode != nullptr) {
			if (currNode == tail) {
				if (tempCurrNode == head) {
					tail = prevNode;
					tail->SetNext(nullptr);
					head = currNode;
					head->SetNext(tempCurrNode);
					cout << "a" << endl;
				}
				else {
					tail = prevNode;
					tail->SetNext(nullptr);
					currNode->InsertAfter(tempPrevNode);
					cout << "b" << endl;
				}
			}
			else if (currNode == head) {
				if (tempCurrNode == currNode->GetNext()) {
					head = currNode->GetNext();
					currNode->InsertAfter(head);
					if (currNode->GetNext() == nullptr) {
						tail = currNode;
					}
					cout << "c" << endl;
				}
				else if (tempCurrNode == tail) {
					head = currNode->GetNext();
					currNode->InsertAfter(tempCurrNode);
					tail = currNode;
					cout << "d" << endl;
				}
				else {
					head = currNode->GetNext();
					currNode->InsertAfter(tempCurrNode);
					cout << "e" << endl;
				}
			}
			else {
				if (tempCurrNode == currNode->GetNext()) {
					prevNode->SetNext(currNode->GetNext());
					currNode->InsertAfter(tempCurrNode);
					cout << "f" << endl;
				}
				else if (tempCurrNode == head) {
					prevNode->SetNext(currNode->GetNext());
					head = currNode;
					head->SetNext(tempCurrNode);
					cout << "g" << endl;
				}
				else if (tempCurrNode == tail) {
					prevNode->SetNext(currNode->GetNext());
					currNode->InsertAfter(tempCurrNode);
					tail = currNode;
					cout << "h" << endl;
				}
				else {
					prevNode->SetNext(currNode->GetNext());
					currNode->InsertAfter(tempPrevNode);
					cout << "i" << endl;
				}
			}
			cout << "\"" << currNode->GetSongName() << "\"" << " was moved to position " << newPosition << endl; 
		}
		else {
			cout << "Could not find correct positions" << endl;
		}
	}	
	else {
		cout << "Could not find correct positions" << endl;
	}
}

void OutputByArtist(PlaylistNode* &head) {
	string artist;
	
	cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
	cout << "Enter artist's name:" << endl;
	getline(cin, artist);
	
	int counter = 1;
	PlaylistNode* currNode = head;
	while (currNode != nullptr) {
		if (currNode->GetArtistName() == artist) {
			cout << counter << "." << endl;
			currNode->PrintPlaylistNode();
		}
		currNode = currNode->GetNext();
		counter += 1;
	}
}

void OutputTime(PlaylistNode* &head) {
	int time = 0;

	cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
	PlaylistNode* currNode = head;
	while (currNode != nullptr) {
		time += currNode->GetSongLength();
		currNode = currNode->GetNext();
	}
	cout << "Total time: " << time << " seconds" << endl;
}

void OutputPlaylist(PlaylistNode* &head, PlaylistNode* &tail) {
	if (head == nullptr) {
		cout << "Playlist is empty" << endl;
	}
	else {
		int playlistNum = 1;
		PlaylistNode* currentSong = head;
		while (currentSong != nullptr) {
			cout << playlistNum++ << "." << endl;
			currentSong->PrintPlaylistNode();
			currentSong = currentSong->GetNext();
			cout << endl;
		}
	}
}

int main() {
	PlaylistNode* head = nullptr;
	PlaylistNode* tail = nullptr;
	string title;
	char option;
	bool shouldQuit = false;
	
	cout << "Enter playlist's title:" << endl;
	getline(cin, title);
	cout << endl;
	
	do {
		PrintMenu(title);
		cin >> option;
		cin.ignore();
		if (option == 'a') {
			AddSong(head, tail);
		}
		else if (option == 'd') {
			RemoveSong(head, tail);
		}
		else if (option == 'c') {
			ChangePosition(head, tail);
		}
		else if (option == 's') {
			OutputByArtist(head);
		}
		else if (option == 't') {
			OutputTime(head);
		}
		else if (option == 'o') {
			cout << title << " - OUTPUT FULL PLAYLIST" << endl;
			OutputPlaylist(head, tail);
		}
		else if (option == 'q') {
			shouldQuit = true;
		}
		else {
			cout << "Invalid input" << endl;
		}
	} while (!shouldQuit);
	
	return 0;
}