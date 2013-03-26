#ifndef __MY_HELP__
#define __MY_HELP__

#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

template<class T>
void printArray(T *array, size_t size) {
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << ", ";
  }
  std::cout << "END" << std::endl;
}

template<class T>
void swap(T &left, T &right) {
  T temp = left;
  left = right;
  right = temp;
}

template<class T>
void swap(T *arr, int left_pos, int right_pos) {
  T temp = arr[left_pos];
  arr[left_pos] = arr[right_pos];
  arr[right_pos] = temp;
}

#define ARRSIZE(a, b) sizeof(a)/sizeof(b)

int randint(int size) {
  return rand() % size;
}

#endif
