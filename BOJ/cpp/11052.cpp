#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> p(n+1);
	rep(i, n) cin >> p[i+1];
	vector<int> dp(n+1, 0);
	dp[0]=0;
	for (int i=1; i<=n; i++) {
		for (int j=i-1; j>=0; j--) {
			dp[i]=max(dp[i], dp[j]+p[i-j]);
		}
	}
	cout << dp[n];

	return 0;
}
