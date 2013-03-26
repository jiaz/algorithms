#include "../helper.hpp"
#include "../datastructure/heap.cpp"

struct ValueWrapper {
  int value;
  size_t pos;

  ValueWrapper() {
    value = 0;
    pos = 0;
  }

  ValueWrapper(int value, size_t pos) {
    this->value = value;
    this->pos = pos;
  }

  ValueWrapper(const ValueWrapper &that) {
    this->value = that.value;
    this->pos = that.pos;
  }

  inline bool operator<(const ValueWrapper &that) const {
    return value < that.value;
  }
};

void printLocalMax(const int *arr, size_t len, size_t window) {
  MaxHeap<ValueWrapper> h;
  for (int i = 0; i < window - 1; ++i) {
    h.add(ValueWrapper(arr[i], i));
  }
  for (int i = window - 1; i < len; ++i) {
    h.add(ValueWrapper(arr[i], i));
    for(;;) {
      ValueWrapper *r = h.top();
      if (i - r->pos < window) {
	cout << r->value << endl;
	break;
      }
      h.pop();
    }
  }
}

int main() {
  int arr[] = {1,6,8,5,4,3,2};
  printLocalMax(arr, ARRSIZE(arr, int), 3);
  return 0;
}
  
  
