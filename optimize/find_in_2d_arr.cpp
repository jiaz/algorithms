#include "../helper.hpp"

using namespace std;

void find_2d_arr(int arr[][3], size_t w, size_t h, int target, int &x, int &y) {
  x = w - 1;
  y = 0;
  while (x >= 0 && y < h) {
    if (arr[y][x] > target) {
      x--;
    } else if (arr[y][x] < target) {
      y++;
    } else if (arr[y][x] == target) {
      return;
    }
  }
  x = -1; y = -1;
}


int main() {
  int arr[][3] = {
    {1,2,3},
    {4,5,6}
  };
  int target = 9;
  int x, y;
  find_2d_arr(arr, 3, 2, target, x, y);
  cout << x << "," << y << endl;
  return 0;
}
