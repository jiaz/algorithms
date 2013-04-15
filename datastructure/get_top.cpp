#include "../helper.hpp"
#include <cstring>
#include <tr1/unordered_map>

using namespace tr1;
using namespace std;

struct TreeNode {
  int count;
  const char *song;
  TreeNode *left;
  TreeNode *right;
};

class TopSong {
private:
  typedef unordered_map<const char*, int> SONGMAP;
  typedef unordered_map<const char*, SONGMAP*> BANDMAP;
  BANDMAP bandMap;
  TreeNode *root;
  
public:
  void playSong(const char *band, const char *song) {
    BANDMAP::iterator it = bandMap.find(band);
    SONGMAP *map;
    if (it == bandMap.end()) {
      map = new SONGMAP();
      bandMap.insert(band, map);
    } else {
      map = it->second;
    }
    SONGMAP::iterator songIt = map->find(song);
    if (songIt == map->end()) {
      map->insert(song, 1);
    } else {
      *songIt = *songIt
  }

  const char *topSong(const char *band) {
    return "abc";
  }
};


int main() {
  TopSong ts;
  ts.playSong("mike", "plays bell");
  cout << ts.topSong("mike") << endl;
  ts.playSong("mike", "hey jue");
  cout << ts.topSong("mike") << endl;
  ts.playSong("mike", "hey jue");
  cout << ts.topSong("mike") << endl;
  return 0;
}
