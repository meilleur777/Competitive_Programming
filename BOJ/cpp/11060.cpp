#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<int> dp(n, 1e6);
	dp[0]=0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<=i+a[i] && j<n; j++) {
			dp[j]=min(dp[j], dp[i]+1);
		}
	}
	if (dp[n-1]==1e6) cout << -1;
	else cout << dp[n-1];

	return 0;
}
