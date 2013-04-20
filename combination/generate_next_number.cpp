#include "../helper.hpp"

/*
find the next greatest number that can be form by same digit of the given number .. 
sample test case 
input 
4765 
output 
5467
*/

int nextGreatestNumber(int input) {
	// find the first decreasing digit from right to left
	queue<int> qu;
	int temp = input;
	int firstDecDigit = -1;
	while (temp != 0) {
		int digit = temp % 10;
		temp /= 10;
		if (qu.size() > 0) {
			if (qu.back() > digit) {
				firstDecDigit = digit;
				break;
			}
		}
		qu.push(digit);
	}
	if (firstDecDigit == -1) return input;
	int frontPart = temp;
	int midDigit = -1;
	int endPart = 0;
	int level = 1;
	for (int i = 0; i < qu.size(); ++i) {
		if (qu.front() > firstDecDigit) {
			midDigit = qu.front();
			endPart *= 10;
			endPart += firstDecDigit;
			level *= 10;
			qu.pop();
			break;
		} else {
			endPart *= 10;
			endPart += qu.front();
			level *= 10;
			qu.pop();
		}
	}
	temp = (frontPart * 10 + midDigit) * level + endPart;
	while (!qu.empty()) {
		temp *= 10;
		temp += qu.front();
		qu.pop();
	}
	return temp;
}

int main() {
	cout << nextGreatestNumber(4321) << endl;
	return 0;
}