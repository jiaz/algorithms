#include "../helper.hpp"

void findNextBigger(int *arr, int *output, int size) {
	stack<int> nextLarges;
	for (int i = size - 1; i >= 0; --i) {
		int current = arr[i];
		if (nextLarges.size() == 0) {
			output[i] = -1;
		} else {
			while (nextLarges.size() > 0) {
				int large = nextLarges.top();
				if (large > current) {
					break;
				}
				nextLarges.pop();
			}
			if (nextLarges.size() > 0) {
				output[i] = nextLarges.top();
			} else {
				output[i] = -1;
			}
		}
		nextLarges.push(current);
	}
}

int main() {
	int arr[] = {2,5,3,4,6,1};
	int output[6];
	findNextBigger(arr, output, 6);
	printArray(output, 6);
	return 0;
}