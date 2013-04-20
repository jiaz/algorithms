#include <algorithm>
#include "../helper.hpp"

#define INT_MIN 1 << 31

/*
You have k lists of sorted integers. Find the smallest range that includes at least one number from each of the k lists. 

For example, 
List 1: [4, 10, 15, 24, 26] 
List 2: [0, 9, 12, 20] 
List 3: [5, 18, 22, 30] 

The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.
*/

struct Interval {
	int start;
	int end;
	Interval(int s, int e) {
		start = s;
		end = e;
	}
};

struct Pair {
	int value;
	int pos;
	int slot;
	Pair(int v, int p, int s) {
		value = v;
		pos = p;
		slot = s;
	}
};

bool compPair(const Pair &left, const Pair &right) {
	return left.value > right.value;
}

Interval *find_smallest_interval_cover(vector<int> **arr, int len) {
	vector<Pair> heap;
	int currentMax = INT_MIN;
	for (int i = 0; i < len; ++i) {
		if (arr[i]->size() > 0) {
			heap.push_back(Pair((*arr[i])[0], 0, i));
			if (currentMax < (*arr[i])[0]) currentMax = (*arr[i])[0];
		} else {
			// not exist
			return NULL;
		}
	}
	make_heap(heap.begin(), heap.end(), compPair);
	Interval *res = new Interval(INT_MIN, INT_MIN);
	int currentStart;
	while (1) {
		// calculate current min
		currentStart = heap.front().value;
		if (res->start == INT_MIN || currentMax - currentStart < (res->end - res->start)) {
			res->end = currentMax;
			res->start = currentStart;
		}
		// adjust next
		pop_heap(heap.begin(), heap.end(), compPair);
		int slot = heap.back().slot;
		int pos = heap.back().pos;
		if (pos < (*arr[slot]).size() - 1) {
			int next = (*arr[slot])[pos + 1];
			if (next > currentMax) currentMax = next;
			heap.pop_back();
			heap.push_back(Pair(next, pos + 1, slot));
		} else break;
	}
	return res;
}

int main() {
	int arr1[] = {4, 10, 15, 24, 26};
	int arr2[] = {0, 9, 12, 20};
	int arr3[] = {5, 18, 22, 30};
	vector<int> *input[3];
	input[0] = new vector<int>(arr1, arr1 + 5);
	input[1] = new vector<int>(arr2, arr2 + 4);
	input[2] = new vector<int>(arr3, arr3 + 4);
	
	Interval *res = find_smallest_interval_cover(input, 3);
	cout << "start: " << res->start << endl;
	cout << "end: " << res->end << endl;
	return 0;
}