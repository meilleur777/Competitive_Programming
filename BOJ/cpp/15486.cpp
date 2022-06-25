#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<intp> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;
	vector<int> dp(n+1, 0);
	rep(i, n) {
		if (i) dp[i]=max(dp[i], dp[i-1]);
		if (i+v[i].first<=n) dp[i+v[i].first]=max(dp[i+v[i].first], dp[i]+v[i].second);
	}
	cout << max(dp[n], dp[n-1]);

	return 0;
}
