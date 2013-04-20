#include "../helper.hpp"
#include <cstring>

using namespace std;

int my_atoi(const char *input, size_t len) {
	if (len == 0) return 0;
	int result = 0;
	bool isNegative = false;
	bool isInvalid = false;
	size_t pos = 0;
	// check sign
	if (input[0] == '-') {
		isNegative = true;
		++pos;
	} else if (input[0] == '+') {
		++pos;
	}
	int base = 10;
	// look for base
	if (len - pos > 2 && input[pos] == '0' && input[pos+1] != 'x') {
		base = 8;
	 	++pos;
	} else if (len - pos > 3 && input[pos] == '0' && input[pos+1] == 'x') {
		base = 16;
		pos += 2;
	}
	// for each digit add the digit to the result
	for (; pos < len; ++pos) {
		char digit = toupper(input[pos]);
		if ((base == 8 && (digit < '0' || digit > '7'))
			|| (base == 10 && (digit < '0' || digit > '9'))
			|| (base == 16 && !((digit >= '0' && digit <= '9') || (digit >= 'A' && digit <= 'F')))
		) {
			isInvalid = true;
			break;
		}
		result *= base;
		result += ((digit >= 'A') ? digit - 'A' : digit - '0');
	}
	
	if (isInvalid) return 0;
	
	return isNegative ? -1 * result : result;
}

int main() {
	const char *input = "-0x12345";
	cout << my_atoi(input, strlen(input)) << endl;
}