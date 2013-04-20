#include "../helper.hpp"

/*
write the most efficient (in terms of time complexity) function getNumberOfPrimes which takes in an integer N as its parameter. 

to return the number of prime numbers that are less than N

Sample Testcases: 
Input #00: 
100 
Output #00: 
25 

Input #01: 
1000000 
Output #01: 
78498
*/

int countPrime(int n) {
	char *buff;
	int len = n / 8 + 1;
	buff = new char[len];

	for (int i = 0; i < len - 1; ++i) {
		buff[i] = 0;
	}
	buff[len - 1] = (char)(0xFF ^ ((1 << (n % 8 + 1)) - 1));
	//cout << (int)buff[len - 1] << endl;
	
	for (int i = 2; i <= n; ++i) {
		if ((buff[i / 8] & (1 << (i % 8))) == 0) {
			int j = i * 2;
			while (j <= n) {
				buff[j / 8] |= (char)(1 << (j % 8));
				j += i;
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < n / 8 + 1; ++i) {
		for (int j = 0; j < 8; ++j)
			if ((buff[i] & (1 << (j))) == 0) {
				//cout << i << ", " << j << "=" << i * 8 + j << endl;
				count++;
			}
	}
	delete [] buff;
	// exclude 0, 1
	return count - 2;
}

int main() {
	int n = 1000000;
	cout << countPrime(n) << endl;
	return 0;
}