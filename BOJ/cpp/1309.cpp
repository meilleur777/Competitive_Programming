#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(3));
	rep(i, 3) dp[0][i]=1;
	for (int i=1; i<n; i++) {
		dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
		dp[i][1]=dp[i-1][0]+dp[i-1][2];
		dp[i][2]=dp[i-1][0]+dp[i-1][1];
		rep(j, 3) dp[i][j]%=9901;
	}
	int ans=0;
	rep(i, 3) ans+=dp[n-1][i];
	cout << ans%9901;

	return 0;
}
