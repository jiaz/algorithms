#include "../helper.hpp"
#include <stdlib.h>


/*
I Got this Crazy Question on PHONE INTERVIEW AT GOOGLE: 

Design and implement a class to generate random numbers in an arbitrary probability distribution given by an array of integer weights, i.e. for int[] w return a number, n, from 0 to w.length - 1 with probability w[n] / sum(w). Using an existing random number generator with a uniform distribution is permitted. 

Example distribution: 
w = 1, 2, 3, 2, 1 

Example probabilities: 
w / sum = 1/9, 2/9, 1/3, 2/9, 1/9 

Example results: 
n = 0, 1, 2, 3, 4 

Documentation: 

Class java.util.Random 

public int nextInt(int n) 

Returns a pseudorandom, uniformly distributed int value between 0 (inclusive) and the specified value (exclusive), drawn from this random number generator's sequence. The general contract of nextInt is that one int value in the specified range is pseudorandomly generated and returned. All n possible int values are produced with (approximately) equal probability. 

Parameters: 
n - the bound on the random number to be returned. Must be positive. 
Returns: 
the next pseudorandom, uniformly distributed int value between 0 (inclusive) and n (exclusive) from this random number generator's sequence 
Throws: 
IllegalArgumentException - if n is not positive
*/

class RandGen {
private:
	int *range;
	int len;
	int sum;
	
	int findInterval(int num) {
		int start = 0;
		int end = len - 1;
		int mid;
		while (start <= end) {
			mid = start + (end - start + 1) / 2;
			if (range[mid] > num) {
				if (mid == 0 || range[mid - 1] <= num) return mid;
				else end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
		// this is impossible
		return -1;
	}

public:
	RandGen(int *dist, int n) {
		len = n;
		sum = 0;
		range = new int[len];
		for (int i = 0; i < len; ++i) {
			sum += dist[i];
			range[i] = sum;
		}
	}
	
	~RandGen() {
		delete []  range;
	}
	
	int next() {
		int nextRand = rand() % sum;
		return findInterval(nextRand);
	}
};

int main() {
	int dist[] = {1, 2, 3, 2, 1};
	RandGen r(dist, 5);
	int count[5] = {0};
	for (int i = 0; i < 1000; ++i) {
		int n = r.next();
		count[n]++;
		cout << n << endl;
	}
	for (int i = 0; i < 5; ++i) {
		cout << count[i] / 1000.0 << endl;
	}
	return 0;
}