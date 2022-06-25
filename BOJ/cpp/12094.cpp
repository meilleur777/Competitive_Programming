#include <iostream>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int n, ans=0;
int board[20][20];

void left() {
	int temp[20][20]={0};

	for (int row=0; row<n; row++) {
		int nxt=0;
		temp[row][0]=board[row][0];
		for (int i=1; i<n; i++) {
			if (board[row][i]==0) continue;
			if (board[row][i]==temp[row][nxt]) {
				temp[row][nxt]*=2;
				nxt++;
			}
			else {
				nxt+=!!temp[row][nxt];
				temp[row][nxt]=board[row][i];
			}
		}
	}

	rep(i, n) rep(j, n) board[i][j]=temp[i][j];
}

void right() {
	int temp[20][20]={0};

	for (int row=0; row<n; row++) {
		int nxt=n-1;
		temp[row][nxt]=board[row][nxt];
		for (int i=n-2; i>=0; i--) {
			if (board[row][i]==0) continue;
			if (board[row][i]==temp[row][nxt]) {
				temp[row][nxt]*=2;
				nxt--;
			}
			else {
				nxt-=!!temp[row][nxt];
				temp[row][nxt]=board[row][i];
			}
		}
	}

	rep(i, n) rep(j, n) board[i][j]=temp[i][j];
}

void up() {
	int temp[20][20]={0};

	for (int col=0; col<n; col++) {
		int nxt=0;
		temp[nxt][col]=board[nxt][col];
		for (int i=1; i<n; i++) {
			if (board[i][col]==0) continue;
			if (board[i][col]==temp[nxt][col]) {
				temp[nxt][col]*=2;
				nxt++;
			}
			else {
				nxt+=!!temp[nxt][col];
				temp[nxt][col]=board[i][col];
			}
		}
	}

	rep(i, n) rep(j, n) board[i][j]=temp[i][j];
}

void down() {
	int temp[20][20]={0};

	for (int col=0; col<n; col++) {
		int nxt=n-1;
		temp[nxt][col]=board[nxt][col];
		for (int i=n-2; i>=0; i--) {
			if (board[i][col]==0) continue;
			if (board[i][col]==temp[nxt][col]) {
				temp[nxt][col]*=2;
				nxt--;
			}
			else {
				nxt-=!!temp[nxt][col];
				temp[nxt][col]=board[i][col];
			}
		}
	}

	rep(i, n) rep(j, n) board[i][j]=temp[i][j];
}

bool chk(int a[][20], int b[][20]) {
	rep(i, n) rep(j, n) if (a[i][j]!=b[i][j]) return true;
	return false;
}

void solve(int count) {
	int mx=0;	
	int memo[20][20];
	rep(i, n) rep(j, n) {
		memo[i][j]=board[i][j];
		mx=max(mx, board[i][j]);
	}
	ans=max(ans, mx);

	if (count==10) return;
	if (mx*(1<<(10-count))<=ans) return;

	left();
	if (chk(memo, board)) {
		solve(count+1);
		rep(i, n) rep(j, n) board[i][j]=memo[i][j];
	}

	right();
	if (chk(memo, board)) {
		solve(count+1);
		rep(i, n) rep(j, n) board[i][j]=memo[i][j];
	}

	up();
	if (chk(memo, board)) {
		solve(count+1);
		rep(i, n) rep(j, n) board[i][j]=memo[i][j];
	}

	down();
	if (chk(memo, board)) {
		solve(count+1);
		rep(i, n) rep(j, n) board[i][j]=memo[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) rep(j, n) cin >> board[i][j];
	solve(0);
	cout << ans;

	return 0;
}
