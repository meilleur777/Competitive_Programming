#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<vector<ll>> dp(3, vector<ll>(1e5+1, 0));
	dp[0][1]=1;
	dp[1][2]=1;
	dp[0][3]=1;
	dp[1][3]=1;
	dp[2][3]=1;
	ll mod=1e9+9;
	for (int i=4; i<=1e5; i++) {
		dp[0][i]=(dp[1][i-1]+dp[2][i-1])%mod;
		dp[1][i]=(dp[0][i-2]+dp[2][i-2])%mod;
		dp[2][i]=(dp[0][i-3]+dp[1][i-3])%mod;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll ans=0;
		rep(i, 3) ans+=dp[i][n];
		ans%=mod;
		cout << ans << '\n';
	}

	return 0;
}
