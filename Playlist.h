#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
using namespace std;

class PlaylistNode {
private:
  string uniqueID;
  string songName;
  string artistName;
  int songLength;
  PlaylistNode* nextNodePtr;
public:
PlaylistNode();
PlaylistNode(string id, string name, string artist, int length);
void InsertAfter(string id,string name,string artist,int length);
void PrintPlaylistNode(PlaylistNode* node);
void SetNext(PlaylistNode* nextNode);
string GetID();
string GetSongName();
string GetArtistName();
int GetSongLength();
PlaylistNode* GetNext();

};

class Playlist {
private:
  PlaylistNode* head;
  PlaylistNode* tail;
public:
  Playlist();

};

#endif
