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

void PlaylistNode::SetNext(PlaylistNode* nextNode) {
  this->nextNodePtr = nextNode;
}

void PlaylistNode::PrintPlaylistNode(PlaylistNode* node) {
  cout << "Unique ID: " << node->GetID();
  cout << "Song Name " << node->GetSongName();
  cout << "Artist Name " << node->GetArtistName();
  cout << "Song Length " << node->GetSongLength();
}
void PlaylistNode::InsertAfter(string id,string name,string artist,int length ) {
  //create a new node
  PlaylistNode* newNode = new PlaylistNode(id, name, artist, length);
   newNode->SetNext(this->GetNext());
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
