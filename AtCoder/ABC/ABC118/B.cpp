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

	int N, M;
	cin >> N >> M;
	vector<int> cnt(M+1, 0);
	rep(i, N) {
		int K;
		cin >> K;
		rep(j, K) {
			int x;
			cin >> x;
			cnt[x]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= M; i++) {
		if (cnt[i] == N) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}
