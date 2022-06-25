#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(n-1, vector<int>(2));
	rep(i, n-1) cin >> a[i][0] >> a[i][1];
	int k;
	cin >> k;
	int INF=0x3f3f3f3f;
	vector<vector<int>> dp(n, vector<int>(2, INF));
	dp[0][0]=0;
	for (int i=1; i<n; i++) {	
				  dp[i][0]=min(dp[i][0], dp[i-1][0]+a[i-1][0]);
		if (i>=2) dp[i][0]=min(dp[i][0], dp[i-2][0]+a[i-2][1]);
		if (i>=3) dp[i][1]=min(dp[i][1], dp[i-3][0]+k);
				  dp[i][1]=min(dp[i][1], dp[i-1][1]+a[i-1][0]);
		if (i>=2) dp[i][1]=min(dp[i][1], dp[i-2][1]+a[i-2][1]);
	}
	cout << min(dp[n-1][0], dp[n-1][1]);

	return 0;
}
