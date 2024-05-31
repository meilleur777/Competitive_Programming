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

	int N;
	cin >> N;
	vector<int> A(N+1);
	rep(i, N) {
		cin >> A[i+1];
	}
	int cnt = 1;
	int but = A[1];
	vector<bool> vis(N+1, false);
	vis[1] = true;
	while (but != 2) {
		if (vis[but]) {
			cout << -1;
			return 0;
		}
		vis[but] = true;
		but = A[but];
		cnt++;
	}
	cout << cnt;

	return 0;
}
