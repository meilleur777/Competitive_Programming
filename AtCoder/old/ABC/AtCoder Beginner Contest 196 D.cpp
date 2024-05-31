#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int cnt = 0;
int H, W, A, B;
vector<vector<int> > board;

void solve(int y, int x, int Au, int Bu) {
	if (!Au && !Bu) {
		cnt++;
		return;
	}
	if (x == W) {
		solve(y+1, 0, Au, Bu);
		return;	
	}
	if (board[y][x]) {
		solve(y, x+1, Au, Bu);
		return;
	}
	board[y][x] = 1;
	if (Au) {
		if (x+1 < W && !board[y][x+1]) {
			board[y][x+1] = 1;
			solve(y, x+2, Au-1, Bu);
			board[y][x+1] = 0;
		}
		if (y+1 < H && !board[y+1][x]) {
			board[y+1][x] = 1;
			solve(y, x+1, Au-1, Bu);
			board[y+1][x] = 0;
		}
	}
	if (Bu) {
		solve(y, x+1, Au, Bu-1);
	}
	board[y][x] = 0;
}

int main() {
	init_code();

	cin >> H >> W >> A >> B;
	board = vector<vector<int> >(H, vector<int>(W, 0));
	solve(0, 0, A, B);
	cout << cnt;

	return 0;
}
