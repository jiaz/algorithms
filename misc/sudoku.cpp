#include "../helper.hpp"

using namespace std;

void set_mark(bool mark[][9], int i, int j, int num, bool flag) {
	mark[i][num - 1] = flag;
	mark[9 + j][num - 1] = flag;
	mark[18 + (i / 3) * 3 + (j / 3)][num - 1] = flag;
}

bool check_mark(bool mark[][9], int i, int j, int num) {
	return !mark[i][num - 1] && !mark[9 + j][num - 1] && !mark[18 + (i / 3) * 3 + (j / 3)][num - 1];
}

int try_count = 0;

bool solve_sodoku(int input[][9], int output[][9]) {
	bool mark[27][9] = {false};
	int i = 0;
	int j = 0;
	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
			int num = input[i][j];
			if (num > 0) {
				output[i][j] = num;
				set_mark(mark, i, j, num, true);
			}
		}
	}
	i = 0; j = 0;
	while (i < 9 && j < 9) {
		if (input[i][j] == 0) {
			int current = output[i][j];
			if (current != 0) {
				set_mark(mark, i, j, current, false);
			}
			int next_try = current;
			do {
				next_try++;
				try_count++;
			} while (next_try <= 9 && !check_mark(mark, i, j, next_try));
			if (next_try > 9) {
				output[i][j] = 0;
				do {
					j--;
					if (j < 0) {
						i--;
						j += 9;
						if (i < 0) return false;
					}
				} while (input[i][j] != 0);
			} else {
				output[i][j] = next_try;
				set_mark(mark, i, j, next_try, true);
				j++;
				if (j >= 9) {
					i++;
					j -= 9;
				}
			}
		} else {
			j++;
			if (j >= 9) {
				i++;
				j -= 9;
			}
		}
	}
	
	return true;
}


int main() {
	int input[9][9] = {
		{0, 0, 5, 3, 0, 0, 0, 0, 0},
		{8, 0, 0, 0, 0, 0, 0, 2, 0},
		{0, 7, 0, 0, 1, 0, 5, 0, 0},
		{4, 0, 0, 0, 0, 5, 3, 0, 0},
		{0, 1, 0, 0, 7, 0, 0, 0, 6},
		{0, 0, 3, 2, 0, 0, 0, 8, 0},
		{0, 6, 0, 5, 0, 0, 0, 0, 9},
		{0, 0, 4, 0, 0, 0, 0, 3, 0},
		{0, 0, 0, 0, 0, 9, 7, 0, 0}
	};
	
	int output[9][9] = {0};
	
	bool solved = solve_sodoku(input, output);
	
	if (solved) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << output[i][j] << ", ";
			}
			cout << "END" << endl;
		}
		cout << try_count << endl;
	} else {
		cout << "No solution." << endl;
	}
	return 0;
}

