#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
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

	int n, m;
	cin >> n >> m;
	vector<bool> a(n+1, true);
	rep(i, m) {
		int x;
		cin >> x;
		a[x]=false;
	}
	vector<ll> dp(n+1, 0);
	dp[0]=1;
	dp[1]=a[1];
	for (int i=2; i<=n; i++) {
		if (!a[i]) continue;
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=mod;
	}
	cout << dp[n];

	return 0;
}
