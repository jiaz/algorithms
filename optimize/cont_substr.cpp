#include "../helper.hpp"
#include <cstring>

using namespace std;

struct range {
  char start;
  char end;
};

void find_cont_substr(const char *str, size_t len, int &start, int &end) {
  // build lookup table
  range lookup[26] = {0};
  for (int i = 0; i < len; ++i) {
    int pos = str[i] - 'a';
    if (lookup[pos].start == 0) {
      lookup[pos].start = str[i];
    }
  }
  char currentRangeStart = 'a' - 1;
  for (int i = 0; i < 26; ++i) {
    if(lookup[i].start != 0) {
      int j = i;
      while (j < 26 && lookup[j].start != 0) j++;
      for (int k = i; k < j; ++k) {
	lookup[k].start = currentRangeStart + 1;
	lookup[k].end = 'a' + j - 1;
      }
    } else {
      currentRangeStart = 'a' + i;
    }
  }
  for (int i = 0; i < 26; ++i) {
    cout << lookup[i].start << ", " << lookup[i].end << endl;
  }
  // scan the string
  int subStart = 0;
  int subEnd = 0;
  int currentStart = 0;
  char currentMin = 'z';
  char currentMax = 'a';
  range *currentRange = &lookup[str[0] - 'a'];
  char map[26] = {0};
  for (int i = 0; i < len; ++i) {
    // check boundary
    if (map[str[i] - 'a'] != 0 || lookup[str[i] - 'a'].start != currentRange->start) {
      cout << i << "," << currentStart << "," << currentMin << "," << currentMax << endl;
      currentStart = i;
      currentMin = 'z';
      currentMax = 'a';
      for (int j = 0; j < 26; ++j) map[j] = 0;
      currentRange = &lookup[str[i] - 'a'];
    }
    map[str[i] - 'a'] = str[i];
    if (str[i] < currentMin) currentMin = str[i];
    else if (str[i] > currentMax) currentMax = str[i];
    if (i - currentStart == currentMax - currentMin && i - currentStart > subEnd - subStart) {
      subStart = currentStart;
      subEnd = i;
    }
  }
  start = subStart;
  end = subEnd;
}   

int main() {
  int start, end = 0;
  const char *t1 = "owlacdebxyz";
  find_cont_substr(t1, strlen(t1), start, end);
  cout << "start: " << start << ", end: " << end << endl;

  return 0;
}
