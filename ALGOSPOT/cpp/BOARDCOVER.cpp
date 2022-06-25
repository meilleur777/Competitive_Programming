#include <iostream>
using namespace std;

int H, W, board[21][21];
const int d[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

bool inRange(int y, int x) {
	if (y >= H || y < 0 || x >= W || x < 0) return false;
	return true;
}

bool set(int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		int ny = y + d[type][i][0], nx = x + d[type][i][1];
		if (!inRange(ny, nx)) ok = false;
		if ((board[ny][nx] += delta) > 1) ok = false;
	}
	return ok;
}

int cover() {
	int y = -1, x = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0 ; j < W; j++) {
			if (!board[i][j]) {
				y = i, x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	
	int result = 0;
	for (int type = 0; type < 4; type++) {
		if (set(y, x, type, 1)) result += cover();
		set(y, x, type, -1);
	}
	return result;	
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string temp;
	int C; cin >> C;
	while (C--) {
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			cin >> temp;
			for (int j = 0; j < W; j++) {
				board[i][j] = (temp[j] == '#') ? 1 : 0;
			}
		}		
		cout << cover()	<< '\n';	
	}	
}

