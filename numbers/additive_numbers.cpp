#include "../helper.hpp"

int log(int num) {
	int len = 1;
	while (num > 9) {
		len++;
		num /= 10;
	}
	return len;
}

int pow(int num, int p) {
	int res = num;
	while (p > 0) {
		res *= 10;
		p--;
	}
	return res;
}

void rec_gen_numbers(int start, int end, int current) {
	int len = log(end);
	
	int maxTryLen = len;
	if (current != 0) {
		len = log(current);
		maxTryLen -= len;
	}
	if (maxTryLen <= 0) return;
	maxTryLen /= 2;
	int maxTry = pow(1, maxTryLen);
	int i = (current == 0) ? 1 : 0;
	for (; i < maxTry; ++i) {
		for (int j = 0; j < maxTry; ++j) {
			int res = i + j;
			res = pow(pow(pow(current, log(i)) + i, log(j)) + j, log(res)) + res;
			if (res >= start && res <= end) {
				cout << res << endl;
			}
			if (res < end)
				rec_gen_numbers(start, end, res);
		}
	}
}

void gen_additive_numbers(int start, int end) {
	if (start > end) return;
	if (start < 0) return;
	
	rec_gen_numbers(start, end, 0);
}

int main() {
	gen_additive_numbers(100, 900000);
	return 0;
}
	