#include "Playlist.h"
#include <iostream>


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
}

Playlist::Playlist() {
	head = nullptr;
	tail = nullptr;
}

void PlaylistNode::SetNext(PlaylistNode* nextNode) {
	this->nextNodePtr = nextNode;
}

void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << this->GetID() << endl;
	cout << "Song Name " << this->GetSongName() << endl;
	cout << "Artist Name " << this->GetArtistName() << endl;
	cout << "Song Length " << this->GetSongLength() << endl;
}
void PlaylistNode::InsertAfter(PlaylistNode* newNode) {
	//new node is node to insert 

	//set next for newpointer to current node->next//

		newNode->SetNext(this->GetNext());
		//insert newnode after current node//
		this->SetNext(newNode);

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

void Playlist::OutputFullPlayList() {
	//check if empty//
	if (head == nullptr) {
		cout << "Playlist is empty" << endl;
	}
	else {
		PlaylistNode* current = head;
		while (current != nullptr) {
			current->PrintPlaylistNode();
			current = current->GetNext();
		}
	}
}

void Playlist::AddSong(string id, string name, string artist, int length) {
	PlaylistNode* newNode = new PlaylistNode(id, name, artist, length);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->SetNext(newNode);
		tail = newNode;
	}
}

void Playlist::RemoveSong(string id) {
	PlaylistNode* currNode = head->GetNext(); 
	PlaylistNode* prevNode = head;
	//traverse through list and keep track of prevNode//
	//when you find node then do prev->next = currNode->next 
	//check when we remove head
	//check when we remove tail
	
	//check if empty//
	if (head == nullptr) {
		return;
	}

	if (prevNode->GetID() == id) {
		head = currNode;
		delete prevNode;
	}

	else {
		while (currNode->GetID() != id) {
			currNode = head->GetNext();
			prevNode = head->GetNext();
		}
		//if we're deleting the tail//
		if (currNode->GetNext() == nullptr) {
			prevNode->GetNext() == nullptr;
			delete currNode;
			tail = prevNode;
		}
		else {
			prevNode->SetNext(currNode->GetNext());
			delete currNode;
		}
	}
}

void Playlist::ChangePosition(int currentPos, int newPos) {
	PlaylistNode* prev = nullptr;
	PlaylistNode* p = head;
	int count = 1;
	//get the node of the current position and its previous node 
	while (count != currentPos) {
		prev = p;
		p = p->GetNext();
		count++;
	}
	PlaylistNode* currentPrev = prev;
	PlaylistNode* currentP = p;

	//get the new position and its previous node 
	PlaylistNode* prev = nullptr;
	PlaylistNode* p = head;
	int count = 1;

	while (count != newPos) {
		prev = p;
		p = p->GetNext();
		count++;
	}
	PlaylistNode* newPrev = prev;
	PlaylistNode* newP = p;

	//if current position is head node
	if (currentPos == 1) {
		head = p->GetNext();
	}

}
