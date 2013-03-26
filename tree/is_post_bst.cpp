#include "../helper.hpp"
#include "tree.cpp"

bool is_post_bst(int *seq, size_t len) {
  if (len <= 1) return true;
  int root = seq[len - 1];
  size_t left_size = 0;
  while(left_size < len - 1 && seq[left_size] < root) ++left_size;
  for (int i = left_size; i < len - 1; ++i) {
    if (seq[i] < root) return false;
  }
  return is_post_bst(seq, left_size) && is_post_bst(seq + left_size, len - left_size - 1);
}
  
int main() {
  int arr[] = {1,2,3,6,5};
  cout << is_post_bst(arr, ARRSIZE(arr, int)) << endl;
  return 0;
}
