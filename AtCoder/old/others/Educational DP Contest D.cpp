#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N, W;
	cin >> N >> W;
	//dp[a]::=the maximum sum of the values when the sum of the weights of items is exactly a
	vector<ll> dp(W+1, 0);
	rep(i, N) {
		ll w, v;
		cin >> w >> v;
		for (int j=W-w; j>=0; j--) {
			dp[j+w]=max(dp[j+w], dp[j]+v);
		}
	}
	ll res=-1;
	rep(i, W+1) res=max(res, dp[i]);
	cout << res;

	return 0;
}
