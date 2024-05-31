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
	vector<int> cnt(1e5+1, 0);
	rep(i, N) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	int ans = cnt[0]+cnt[1];
	for (int i = 1; i < 1e5; i++) {
		ans = max(ans, cnt[i-1]+cnt[i]+cnt[i+1]);
	}
	ans = max(ans, cnt[1e5-1]+cnt[1e5]);
	cout << ans;
	
	return 0;
}
