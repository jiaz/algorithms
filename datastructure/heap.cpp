#include "../helper.hpp"
#include <cstring>

using namespace std;

template<class T>
class MaxHeap {
private:
  T *buffer;
  size_t alloc_size;
  size_t used_size;

public:
  MaxHeap() {
    // placeholder slot
    buffer = new T[1];
    alloc_size = used_size = 1;
  }

  ~MaxHeap() {
    delete[] buffer;
  }

  void add(const T &value) {
    if (alloc_size == used_size) {
      expand();
    }
    buffer[0] = value;
    used_size++;
    size_t pos = adjustHeap();
    buffer[pos] = buffer[0];
  }

  size_t size() {
    return used_size - 1;
  }

  T *pop() {
    if (size() <= 0) return NULL;
    T *res = new T(buffer[1]);
    buffer[0] = buffer[used_size - 1];
    used_size--;
    size_t pos = adjustHeapHead();
    buffer[pos] = buffer[0];
    return res;
  }

  T *top() {
    if (size() <= 0) return NULL;
    return &buffer[1];
  }

private:
  void expand() {
    size_t new_size = alloc_size * 2 + 10;
    T *new_buffer = new T[new_size];
    memcpy(new_buffer, buffer, alloc_size * sizeof(T));
    delete [] buffer;
    buffer = new_buffer;
    alloc_size = new_size;
  }

  size_t adjustHeapHead() {
    size_t pos = 1;
    for(;;) {
      size_t next_pos_l = pos * 2;
      size_t next_pos_r = next_pos_l + 1;
      if (next_pos_l < used_size) {
	size_t next_pos;
	if (next_pos_r < used_size) {
	  next_pos = ((buffer[next_pos_l] < buffer[next_pos_r]) ? next_pos_r : next_pos_l);
	} else {
	  next_pos = next_pos_l;
	}
	if (buffer[next_pos] < buffer[0]) return pos;
	buffer[pos] = buffer[next_pos];
	pos = next_pos;
      } else {
	return pos;
      }
    }
  }
  
  size_t adjustHeap() {
    size_t pos = used_size - 1;
    size_t parent;
    for(;;) {
      parent = pos / 2;
      if (parent == 0) return pos;
      if (buffer[parent] < buffer[0]) {
	buffer[pos] = buffer[parent];
      } else {
	return pos;
      }
      pos = parent;
    }
  }
};
