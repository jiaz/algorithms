#include "../helper.hpp"
#include <vector>
using namespace std;

size_t uniq_sort(int *arr, size_t len) {
  return len;
}

void print_uniq_tuples(int *arr, size_t len, size_t window) {
  if (len == 0 || window == 0) return;
  
  size_t uniq_len = uniq_sort(arr, len);
  if (window >= uniq_len) {
    printArray(arr, uniq_len);
    return;
  }
  vector<size_t> pos;
  int level = 1;
  while(level > 0) {
    if (level == window + 1) {
      printArray(arr, window);
      level--;
    } else {
      if (pos.size() < level) {
	pos.push_back(level - 1);
      } else {
	size_t lastpos = pos[level - 1];
	swap(arr, lastpos, level - 1);
	pos.pop_back();
	pos.push_back(++lastpos);
      }	
      if (pos[level - 1] >= uniq_len) {
	pos.pop_back();
	level--;
      } else {
	swap(arr, pos[level-1], level - 1);
	if (level == 1 || arr[level - 1] > arr[level - 2]) level++;
      }
    }
  }
}

int main() {
  int arr[] = {1,2,3,4,5};
  print_uniq_tuples(arr, 5, 2);
  return 0;
}
