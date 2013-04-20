#include "../helper.hpp"

/*
Special Property Numbers: 
Eg--> You have a number 8987656 or 4565676 
The difference between consecutive numbers is either 1 or -1. 

You are given a range, you need to print the numbers with this special property.
*/

void rec_gen_number(int start, int end, int current, int len) {
	if (current >= start && current <= end) cout << current << endl;
	if (len == 0) return;
	int lastDigit = current % 10;
	if (lastDigit > 0) {
		rec_gen_number(start, end, current * 10 + lastDigit - 1, len - 1);
	}
	if (lastDigit < 9) {
		rec_gen_number(start, end, current * 10 + lastDigit + 1, len - 1);
	}
}

void gen_consecutive_numbers(int start, int end) {
	if (start > end) return;
	if (start < 0) return;
	int len = 1;
	int temp = end;
	while (temp >= 10) {
		temp /= 10;
		len++;
	}
	for (int i = 1; i < 9; ++i)
		rec_gen_number(start, end, i, len - 1);
}

int main() {
	gen_consecutive_numbers(100, 1000000);
	return 0;
}