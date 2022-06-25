#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> dp(n, vector<int>(m, 0));
	int ans=0;
	rep(i, n) rep(j, m) {
		dp[i][j]=a[i][j]-'0';
		ans=max(ans, dp[i][j]);
	}
	for (int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			if (dp[i][j]==1) dp[i][j]=min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+1;
			ans=max(ans, dp[i][j]);
		}
	}
	cout << ans*ans;

	return 0;
}
