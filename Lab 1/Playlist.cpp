#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

PlaylistNode::PlaylistNode() {
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string id, string name, string artist, int length) {
	uniqueID = id;
	songName = name;
	artistName = artist;
	songLength = length;
	nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* &node) {
	PlaylistNode* tempNode = node->nextNodePtr;
	node->SetNext(this);
	this->SetNext(tempNode);
}

void PlaylistNode::SetNext(PlaylistNode* node) {
	if (node == nullptr) {
		nextNodePtr = nullptr;
	}
	else {
		nextNodePtr = node;
	}
}

string PlaylistNode::GetID() {
	return uniqueID;
}

string PlaylistNode::GetSongName() {
	return songName;
}

string PlaylistNode::GetArtistName() {
	return artistName;
}

int PlaylistNode::GetSongLength() {
	return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
	return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << uniqueID << endl;
	cout << "Song Name: " << songName << endl;
	cout << "Artist Name: " << artistName << endl;
	cout << "Song Length (in seconds): " << songLength << endl;
}