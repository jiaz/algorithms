#include "../helper.hpp"

void printAllPerm(char *input, int len, int pos) {
	if (pos == len - 1) {
		cout << input << endl;
		return;
	}
	for (int i = pos; i < len; ++i) {
		char temp = input[pos];
		input[pos] = input[i];
		input[i] = temp;
		printAllPerm(input, len, pos + 1);
		input[i] = input[pos];
		input[pos] = temp;
	}
}

int main() {
	char buff[] = {
		'c', 'a', 'r', 'b', 'o', 'n', 0
	};
	printAllPerm(buff, sizeof(buff) / sizeof(char) - 1, 0);
	return 0;
}