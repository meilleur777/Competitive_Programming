#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> dp(2, vector<int>(n, -1e8-1));
	dp[0][0]=a[0];
	for (int i=1; i<n; i++) {
		dp[0][i]=max(dp[0][i-1]+a[i], a[i]);
		dp[1][i]=max(dp[0][i-1], dp[1][i-1]+a[i]);
	}
	int ans=-1e8-1;
	rep(i, 2) rep(j, n) ans=max(ans, dp[i][j]);
	cout << ans;

	return 0;
}
