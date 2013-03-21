#include "../helper.hpp"

using namespace std;

void getMaxSubArray2(int *arr, size_t len, int &sum, int &start, int &end) {
  if (len <= 0) {
    sum = 0;
    start = -1;
    end = -1;
    return;
  }
  start = end = 0;
  sum = arr[0];
  int ss = 0; int ssum = 0;
  for (int i = 0; i < len; ++i) {
    ssum += arr[i];
    if (ssum > sum) {
      sum = ssum;
      start = ss;
      end = i;
    }
    if (ssum < 0) {
      ssum = 0;
      ss = i + 1;
    }
  }
}

int main() {
  int sum, start, end;
  int arr[] = {1};
  getMaxSubArray2(arr, 1, sum, start, end);
  cout << sum << ", " << start << ", " << end << endl;

  int arr2[] = {1,2};
  getMaxSubArray2(arr2, 2, sum, start, end);
  cout << sum << ", " << start << ", " << end << endl;

  int arr3[] = {-1,3,1,321,-34,12,4,-53,75,-45,4,3,-5,3};
  getMaxSubArray2(arr3, ARRSIZE(arr3, int), sum, start, end);
  cout << sum << ", " << start << ", " << end << endl;

  int arr4[] = {-2, -1};
  getMaxSubArray2(arr4, ARRSIZE(arr4, int), sum, start, end);
  cout << sum << ", " << start << ", " << end << endl;

  return 0;
}
