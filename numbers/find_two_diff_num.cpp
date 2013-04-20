#include "../helper.hpp"

void printTwoDiffNumber(int *arr, int size) {
	int res = 0;
	for (int i = 0; i < size; ++i) {
		res ^= arr[i];
	}
	int res2 = (res - 1) & res;
	int diffBit = res ^ res2;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < size; ++i) {
		if ((arr[i] & diffBit) != 0) {
			num1 ^= arr[i];
		} else {
			num2 ^= arr[i];
		}
	}
	cout << num1 << endl;
	cout << num2 << endl;
}


int main() {
	int arr[] = {1,1,5,6,3,4,4,3,-1,-1,-9,-9,5,9};
	printTwoDiffNumber(arr, ARRSIZE(arr, int));
	return 0;
}