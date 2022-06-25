#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
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

int main() {
	init_code();

	int board[4][4];
	rep(i, 3) rep(j, 3) cin >> board[i][j];
	int N;
	cin >> N;
	rep(i, N) {
		int n;
		cin >> n;
		rep(j, 3) rep(k, 3) {
			if (board[k][j]==n) {
				board[k][j]=-1;
			}
		}
	}
	bool flag=false;
	for (int i=0; i<3; i++) {
		if (board[i][0]==-1 && board[i][1]==-1 && board[i][2]==-1) {
			flag=true;
		}
		if (board[0][i]==-1 && board[1][i]==-1 && board[2][i]==-1) {
			flag=true;
		}
	}
	if (board[0][0]==-1 && board[1][1]==-1 && board[2][2]==-1) {
		flag=true;
	}
	if (board[0][2]==-1 && board[1][1]==-1 && board[2][0]==-1) {
		flag=true;
	}
	if (flag) cout << "Yes";
	else cout << "No";

	return 0;
}
