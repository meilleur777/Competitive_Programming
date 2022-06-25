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
	cout << fixed;
	cout.precision(5);

	int k, n;
	while (cin >> k >> n) {
		vector<vector<ld> > dp(10, vector<ld>(101, 0.0));
		for (int i=0; i<=k; i++) dp[i][1]=100.0/(k+1);
		for (int i=2; i<=n; i++) {
			for (int j=0; j<=k; j++) {
				if (j-1>=0) dp[j][i]+=dp[j-1][i-1]/(k+1);
				if (j+1<=k) dp[j][i]+=dp[j+1][i-1]/(k+1);
				dp[j][i]+=dp[j][i-1]/(k+1);
			}
		}
		ld ans=0.0;
		for (int i=0; i<=k; i++) ans+=dp[i][n];
		cout << ans << '\n';
	}

	return 0;
}
