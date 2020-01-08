#include <iostream>
#include "Playlist.h"
using namespace std;


int main() {
  PlaylistNode* curr = head;
  PlaylistNode* testNode;
  string testName = "Kill This Love";
  string testArtist = "Blackpink";
  int testLength = "300"
  InsertAfter(testNode, testName, testArtist, testLength);

  while (curr != nullptr) {
    PrintPlaylistNode(curr);
    cout << endl;
    curr = curr->nextNodePtr;
  }

  return 0;

}
