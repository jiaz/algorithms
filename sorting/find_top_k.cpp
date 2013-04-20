#include "../helper.hpp"

bool compare(const int &left, const int &right) {
	return left > right;
}

class TopK {
private:
	vector<int> heap;
	int k;
	
public:
	TopK(int k) {
		this->k = k;
	}

	void consume(int input) {
		if (heap.size() < k) {
			heap.push_back(input);
			make_heap(heap.begin(), heap.end(), compare);
		} else {
			if (input > heap[0]) {
				pop_heap(heap.begin(), heap.end(), compare);
				heap.pop_back();
				heap.push_back(input);
				make_heap(heap.begin(), heap.end(), compare);
			}
		}
	}
	
	void printTopK() {
		for (int i = 0; i < heap.size(); ++i) {
			cout << heap[i] << ",";
		}
		cout << "END" << endl;
	}
};

int main() {
	int arr[] = {1, 3, 2, 6, 9, 2, 4, 1, 5, 0, 8};
	TopK tk(3);
	for (int i = 0; i < ARRSIZE(arr, int); ++i) {
		tk.consume(arr[i]);
		tk.printTopK();
	}
	return 0;
}