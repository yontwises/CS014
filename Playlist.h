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
	void InsertAfter(PlaylistNode* Node);
	void PrintPlaylistNode();
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
	void OutputFullPlayList();
	void AddSong(string id, string name, string artist, int length);
	void RemoveSong(string id);
	void ChangePosition(int currentPos, int newPos);
};

#endif
