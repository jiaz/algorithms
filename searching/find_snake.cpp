#include "../helper.hpp"

/*
You are given a 2-D array with same number of rows and columns. You have to determine the longest snake in the array. The property to find the snake is the difference between the adjacent(left, right, up or down) should be either 1 or -1. If there are more than one snakes with maximum length, the output should print both of them. 

Example--> 

The given array elements are as follows: 

4	7	9	8 
5	6	5	4 
6	7	8	5 
10	9	7	6 
*/

struct node {
	int x;
	int y;
	node (int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int abs(int a) {
	return (a < 0) ? -a : a;
}

int xop[] = {1, -1, 0, 0};
int yop[] = {0, 0, 1, -1};

vector< vector<node> > result;

void recPrintLongestSnake(int *snakemap, int n, bool *mark, vector<node> &path, int &maxLen) {
	const node &last = path.back();
	bool isDead = true;
	for (int i = 0; i < 4; ++i) {
		int nextX = last.x + xop[i];
		int nextY = last.y + yop[i];
		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n
			&& !mark[nextX + n * nextY]
			&& abs(snakemap[nextX + n * nextY] - snakemap[last.x + n * last.y]) == 1) {
			isDead = false;
			mark[nextX + n * nextY] = true;
			path.push_back(node(nextX, nextY));
			recPrintLongestSnake(snakemap, n, mark, path, maxLen);
			path.pop_back();
			mark[nextX + n * nextY] = false;
		}
	}
	if (isDead) {
		if (path.size() > maxLen) {
			// clear old add new
			result.clear();
			result.push_back(path);
			maxLen = path.size();
		} else if (path.size() == maxLen) {
			// append solution
			result.push_back(path);
		}
	}
}

void printLongestSnake(int *snakemap, int n) {
	bool *mark = new bool[n * n];
	memset(mark, 0, sizeof(bool) * n * n);
	vector<node> path;
	int maxLen = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			mark[n * j + i] = 1;
			path.push_back(node(i, j));
			recPrintLongestSnake(snakemap, n, mark, path, maxLen);
			mark[n * j + i] = 0;
			path.pop_back();
		}
	}
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << snakemap[result[i][j].x + result[i][j].y * n] << "->";
		}
		cout << "END" << endl;
	}
	delete [] mark;
}

int main() {
	int snakemap[] = {
		4, 7, 9, 8,
		5, 6, 5, 4,
		6, 7, 8, 5,
		10, 9, 7, 6
	};
	printLongestSnake(snakemap, 4);
	return 0;
}