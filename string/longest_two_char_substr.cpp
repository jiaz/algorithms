#include "../helper.hpp"

/*
Given a string.Find the longest substring in it such that the substring contains only 2 unique characters.Ex- aabbcbbbadef Ans-bbcbbb
*/

void find_longest_two_char_substr(const char *str, int len, const char *&output, int &outlen) {
	char uniq_chars[2] = {str[0], 0};
	int char_pos[2] = {0, -1};
	char lastChar = str[0];
	int lastPos = 0;
	int currentStart = 0;
	int currentMaxLen = 0;
	const char *currentRes = str;
	for (int i = 1; i < len; ++i) {
		if (str[i] != lastChar) {
			int currentPos = (1 + lastPos) % 2;
			if (uniq_chars[currentPos] == str[i]) {
				uniq_chars[currentPos] = str[i];
				char_pos[currentPos] = i;
			} else {
				// new char
				currentStart = char_pos[lastPos];
				char_pos[currentPos] = i;
				uniq_chars[currentPos] = str[i];
			}
			lastChar = str[i];
			lastPos = currentPos;
		} else {
			if (currentMaxLen < i - currentStart + 1) {
				currentMaxLen = i - currentStart + 1;
				currentRes = str + currentStart;
			}
		}
	}
	output = currentRes;
	outlen = currentMaxLen;
}

int main() {
	const char *str = "aabbcbbbadef";
	const char *res;
	int len;
	find_longest_two_char_substr(str, strlen(str), res, len);
	cout << res << endl;
	cout << len << endl;
	return 0;
}