#include <iostream>

#include "helper.hpp"

using namespace std;

template<class T>
void insertion_sort(T *data, size_t size) {
  if(size <= 1) return;
  for(int i = 1; i < size; ++i) {
    int j = i;
    T temp = data[j];
    while(j > 0 && temp < data[j-1]) {
      data[j] = data[j-1];
      j--;
    }
    data[j] = temp;
  }
}

int main(int argc, char** argv) {
  int simple_case[] = {1, 2, 3, 4, 5};
  insertion_sort(simple_case, 5);
  printArray(simple_case, 5);

  int complex_case[] = {5,1,23,5,6,1,2,5,6,9};
  insertion_sort(complex_case, sizeof(complex_case)/sizeof(int));
  printArray(complex_case, sizeof(complex_case)/sizeof(int));
  return 0;
}
