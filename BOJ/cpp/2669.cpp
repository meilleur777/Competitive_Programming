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

int main() {
	init_code();

	vector<vector<bool> > chk(101, vector<bool>(101, false));
	rep(i, 4) {
		int ax, ay, bx, by;	
		cin >> ax >> ay >> bx >> by;
		for (int j = ax; j < bx; j++) {
			for (int k = ay; k < by; k++) {
				chk[j][k] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			ans += chk[i][j];
		}
	}
	cout << ans;

	return 0;
}
