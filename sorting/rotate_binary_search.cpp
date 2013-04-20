#include "../helper.hpp"

using namespace std;

int rotate_bs(int *arr, size_t start, size_t end, int target) {
	if (end < start) return -1;
	if (start == end) return (arr[start] == target) ? start : -1;
	size_t mid = start + (end - start + 1) / 2;
	if (arr[mid] == target) {
		size_t peek = rotate_bs(arr, start, mid - 1, target);
		return (peek == -1) ? mid : peek;
	}
	if (arr[mid] > arr[start]) {
		if (arr[mid] > target) {
			if (arr[start] > target) {
				return rotate_bs(arr, mid + 1, end, target);
			} else {
				return rotate_bs(arr, start, mid - 1, target);
			}
		} else {
			return rotate_bs(arr, mid + 1, end, target);
		}
	} else {
		if (arr[mid] > target) {
			return rotate_bs(arr, start, mid - 1, target);
		} else {
			if (arr[start] > target) {
				return rotate_bs(arr, mid + 1, end, target);
			} else {
				return rotate_bs(arr, start, mid - 1, target);
			}
		}
	}
	return -1;
}

int main() {
	int arr[] = {6,7,8,1,1,1,1,1,1,3,3,5};
	
	cout << rotate_bs(arr, 0, ARRSIZE(arr, int) - 1, 6) << endl;
	
	return 0;
}