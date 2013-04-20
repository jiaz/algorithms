#include "../helper.hpp"

int longestSequence(int *arr, int size) {
	if (size <= 1) return 1;
	int *diff = new int[size - 1];
	for (int i = 0; i < size - 1; ++i) {
		diff[i] = arr[i + 1] - arr[i];
	}
	
	int currDiff = diff[0];
	int maxLen = 1;
	int currLen = 1;
	for (int i = 1; i < size - 1; ++i) {
		if (diff[i] == currDiff) currLen++;
		else {
			if (currLen > maxLen) maxLen = currLen;
			currLen = 1;
			currDiff = diff[i];
		}
	}
	return maxLen + 1;
}

int main() {
	int arr[] = {-1, 1, 3, 7, 11, 15, 19, 20, 21, 22};
	cout << longestSequence(arr, ARRSIZE(arr, int)) << endl;
	return 0;
}