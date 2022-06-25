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

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<intp>> edge(n);
	rep(i, k) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		if (a>b) continue;
		edge[b].push_back({a, c});
	}
	vector<vector<int>> dp(n, vector<int>(m+1, -INF));
	dp[0][0]=0;
	for (int i=1; i<n; i++) {
		for (auto l:edge[i]) {
			if (l.first==0) {
				dp[i][1]=max(dp[i][1], l.second);
			}
		}
		for (int j=2; j<m; j++) {
			for (auto l:edge[i]) {
				dp[i][j]=max(dp[i][j], l.second+dp[l.first][j-1]);
			}
			
		}
	}
	int ans=-1;
	rep(i, m) ans=max(ans, dp[n-1][i]);
	cout << ans;

	return 0;
}
