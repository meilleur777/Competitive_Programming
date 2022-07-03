#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	dp[0][0]=1;
	rep(i, n) rep(j, n) cin >> a[i][j];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i==n-1 && j==n-1) cout << dp[i][j];
			if (j+a[i][j]<n) dp[i][j+a[i][j]]+=dp[i][j];
			if (i+a[i][j]<n) dp[i+a[i][j]][j]+=dp[i][j];
		}
	}

	return 0;
}
