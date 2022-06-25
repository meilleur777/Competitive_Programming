#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int cache[19700];
char board[3][3];

bool isFinished(char turn) {
	int asum, bsum;
	for (int i = 0; i < 3; i++) {
		asum = bsum = 0;
		for (int j = 0; j < 3; j++) { asum += board[i][j]; bsum += board[j][i]; }
		if (asum == turn * 3 || bsum == turn * 3) return true;
	}
	asum = bsum = 0;
	for (int i = 0; i < 3; i++) { asum += board[i][i]; bsum += board[i][2 - i]; }
	if (asum == turn * 3 || bsum == turn * 3) return true;
	return false;
}

int bijection() {
	int ret = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			ret = ret * 3;
			if (board[y][x] == 'o') ret++;
			else if (board[y][x] == 'x') ret += 2;
		}
	}
	return ret;
}

/*이길 수 있는 경우 1, 비길 수 있으면 0, 질 수밖에 없으면 -1*/
int canWin(char turn) {
	if (isFinished('o' + 'x' - turn)) return -1;
	
	int& ret = cache[bijection()];
	if (ret != -2) return ret;
	
	int minValue = 2;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (board[y][x] == '.') {
				board[y][x] = turn;
				minValue = min(minValue, canWin('o' + 'x' - turn));
				board[y][x] = '.';
			}
		}
	}
	if (!minValue || minValue == 2) return ret = 0;
	return ret = -minValue;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		int ocount = 0, xcount = 0;
		fill(cache, cache + 19700, -2);
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'o') ocount++;
				else if (board[i][j] == 'x') xcount++;
			}
		}
		char currentTurn = ocount < xcount ? 'o' : 'x';
		switch(canWin(currentTurn)) {
			case 1: cout << currentTurn << '\n'; break;
			case 0: cout << "TIE\n"; break;
			case -1: cout << (char)('o' + 'x' - currentTurn) << '\n';
		}
	}		
}

