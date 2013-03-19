#ifndef __MY_HELP__
#define __MY_HELP__

#include <iostream>

template<class T>
void printArray(T *array, size_t size) {
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << ", ";
  }
  std::cout << "END" << std::endl;
}

#endif
