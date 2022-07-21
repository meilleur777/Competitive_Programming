#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	int INF=0x3f3f3f3f;
	vector<int> dp(1e5+1, INF);
	dp[2]=1;
	dp[5]=1;
	dp[4]=2;
	for (int i=6; i<=n; i++) {
		dp[i]=min(dp[i-2], dp[i-5])+1;
	}
	if (dp[n]!=INF) cout << dp[n];
	else cout << -1;

	return 0;
}
