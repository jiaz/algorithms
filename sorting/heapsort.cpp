#include <iostream>
#include <cstring>
#include "../helper.hpp"

using namespace std;

class Heap {
public:
  int *container;
  size_t container_size;
  
public:
  void build(int *arr, size_t size) {
    container_size = size;
    container = new int[container_size];
    memcpy(container, arr, container_size * sizeof(int));
    for (int i = container_size / 2; i >= 0; --i) {
      adjust(i);
    }
  }

  void adjust(size_t pos) {
    while(2 * pos + 1 < container_size) {
      int smaller_child;
      if (2 * pos + 2 >= container_size) {
	smaller_child = 2 * pos + 1;
      } else {
	smaller_child = (container[2 * pos + 1] < container[2 * pos + 2])
	  ? 2 * pos + 1
	  : 2 * pos + 2;
      }
      if (container[pos] > container[smaller_child]) {
	swap(container, pos, smaller_child);
	pos = smaller_child;
      } else {
	break;
      }
    }
  }
  
  int pop() {
    int res = container[0];
    swap(container, 0, container_size - 1);
    container_size--;
    adjust(0);
    return res;
  }

  bool isEmpty() {
    return container_size == 0;
  }
};

void printHeap(Heap &h) {
  while(!h.isEmpty()) {
    cout << h.pop() << ", ";
  }
  cout << "END" << endl;
}

int main(int argc, char **argv) {
  int simple[] = {1,2,3,4,5,6,7};
  Heap h;
  h.build(simple, ARRSIZE(simple, int));
  printHeap(h);

  int complex[] = {12,2,4,5,1,3,5,6,1,23,5,7,8,7,5};
  Heap h2;
  h2.build(complex, ARRSIZE(complex, int));
  printHeap(h2);
  return 0;
}
