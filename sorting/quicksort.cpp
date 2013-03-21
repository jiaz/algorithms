#include <iostream>
#include "../helper.hpp"

using namespace std;

void internal_qsort(int *arr, size_t start, size_t end) {
  if (end <= start + 1) {
    return;
  }
  int piviot = randint(end - start) + start;
  swap(arr, start, piviot);
  int i = start;
  int j = end - 1;
  while (i < j) {
    while(i < end && arr[i] <= arr[start]) ++i;
    while(j >= start && arr[j] > arr[start]) --j;
    if (i < j) {
      swap(arr, i, j);
    }
  }
  swap(arr, start, j);
  internal_qsort(arr, start, j);
  internal_qsort(arr, i, end);
}
    
void qsort(int *arr, size_t len) {
  internal_qsort(arr, 0, len);
}

int main(int argc, char **argv) {
  int simple[] = {1,3,4,5};
  qsort(simple, ARRSIZE(simple, int));
  printArray(simple, ARRSIZE(simple, int));

  int complex[] = {1,2,5,1,41,2,5,3,4,6,724,1,334,6,1,13,5,8};
  qsort(complex, ARRSIZE(complex, int));
  printArray(complex, ARRSIZE(complex, int));
  return 0;
}
