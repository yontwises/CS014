#include "Playlist.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


int main() {
	// std::cout << "Hello World! " << '\n';
	// Playlist list//
	Playlist list;

	list.AddSong("H103", "DuDu", "Blackpink", 340);
	list.AddSong("H523", "Kill This Love ", "Blackpink", 200);
	list.AddSong("H523", "Kill This Love ", "Blackpink", 200);
	list.AddSong("H523", "Kill This Love ", "Blackpink", 200);
	/*list.OutputFullPlayList();*/
	list.RemoveSong("H523");
	list.OutputFullPlayList();
	// testNode->InsertAfter(testID, testName, testArtist, testLength);

	

	return 0;

}
