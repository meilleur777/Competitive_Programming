#include <iostream>
#include <string.h>
using namespace std;

int n;
int cache[101][101];
int board[101][101];

int solve(int y, int x) {
	if (y >= n || x >= n) return false;
	if (y == n - 1 && x == n - 1) return true;
	
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return ret = (solve(y + board[y][x], x) || solve(y, x + board[y][x]));
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		if (solve(0, 0) == 1) cout << "YES\n";
		else cout << "NO\n";
	}	
}

