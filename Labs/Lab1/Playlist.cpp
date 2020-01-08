#include "Playlist.h"
#include <iostream>


PlaylistNode::PlaylistNode() {
  uniqueID = "none";
  songName = "none";
  artistName = "none";
  songLength = 0;
  nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string id,string name,string artist,int length) {
  uniqueID = id;
  songName = name;
  artistName = artist;
  songLength = length;
}

Playlist::Playlist() {
  head = nullptr;
  tail = nullptr;
}

void PlaylistNode::SetNext(PlaylistNode* node, PlaylistNode* nextNode) {
  if (node = nullptr) {
    return;
  }
  else {
    node->nextNodePtr = nextNode;
  }

}

void Playlist::PrintPlaylistNode(PlaylistNode* node) {
  cout << "Unique ID: " << node->GetID();
  cout << "Song Name " << node->GetSongName();
  cout << "Artist Name " << node->GetArtistName();
  cout << "Song Length " << node->GetSongLength();
}
void PlaylistNode::InsertAfter(PlaylistNode* prevNode,string id,string name,string artist,int length ) {
  //create a new node
  PlaylistNode* newNode = new PlaylistNode(id, name, artist, length);
  //empty//
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  }
  else if (prevNode == tail) {
    SetNext(tail, newNode);
    // tail->nextNodePtr = newNode;
    tail = newNode;
  }
  else {
    SetNext(newNode,prevNode->GetNext());
    // newNode->nextNodePtr = prevNode->nextNodePtr;
    // prevNode->next = newNode;
    SetNext(prevNode, newNode);
  }
}

string PlaylistNode::GetID() {
  return uniqueID;
}
string PlaylistNode::GetSongName() {
  return songName;
}
string PlaylistNode::artistName() {
  return artistName;
}
int PlaylistNode::GetSongLength() {
  return songLength;
}
PlaylistNode* PlaylistNode::GetNext() {
  return nextNodePtr;
}
