#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n), dp(k+1, 1e7);
	rep(i, n) cin >> a[i];
	dp[0]=0;
	for (int i=0; i<n; i++) {
		for (int j=a[i]; j<=k; j++) {
			dp[j]=min(dp[j], dp[j-a[i]]+1);
		}
	}
	if (dp[k]!=1e7) cout << dp[k];
	else cout << -1;

	return 0;
}
