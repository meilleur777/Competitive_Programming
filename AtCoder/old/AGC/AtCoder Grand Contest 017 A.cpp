#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<ll>> dp(2, vector<ll>(n, 0));
	dp[0][0]=1;
	dp[a[0]%2][0]++;
	for (int i=1; i<n; i++) {
		dp[0][i]+=dp[0][i-1];
		dp[1][i]+=dp[1][i-1];
		if (a[i]%2) {
			dp[0][i]+=dp[1][i-1];
			dp[1][i]+=dp[0][i-1];
		}
		else {
			dp[0][i]+=dp[0][i-1];
			dp[1][i]+=dp[1][i-1];
		}
	}
	cout << dp[p][n-1];	

	return 0;
}
