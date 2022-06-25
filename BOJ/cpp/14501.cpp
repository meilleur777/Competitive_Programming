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

	int n;
	cin >> n;
	vector<int> t(n), p(n);
	rep(i, n) cin >> t[i] >> p[i];
	vector<int> dp(n+1, 0);
	for (int i=0; i<n; i++) {
		if (i!=0) dp[i]=max(dp[i], dp[i-1]);
		int tmp=i+t[i];
		if (tmp<n+1) {
			dp[tmp]=max(dp[tmp], dp[i]+p[i]);
		}
	}
	dp[n]=max(dp[n], dp[n-1]);
	cout << dp[n];

	return 0;
}
