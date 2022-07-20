#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> dp(n+1, 0);
	dp[0]=1	;
	int mod=1e9;
	for (int i=1; i<=n; i++) {
		if (i%2)  dp[i]=dp[i-1];
		else dp[i]=(dp[i-1]+dp[i/2])%mod;
	}
	cout << dp[n];

	return 0;
}
