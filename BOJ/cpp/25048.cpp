#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n;
	vector<intp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;
	cin >> m;
	vector<ll> dp(m+1, 1e15);
	dp[1]=0;
	for (int i=0; i<n; i++) {
		for (int j=m; j-(a[i].first-2)>=1; j--) {
			if (dp[j-(a[i].first-2)]==1e15) continue;
			dp[j]=min(dp[j], dp[j-(a[i].first-2)]+a[i].second);
		}
	}
	if (dp[m]==1e15) cout << -1;
	else cout << dp[m];

	return 0;
}
