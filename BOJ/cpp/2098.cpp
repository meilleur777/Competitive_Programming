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
	vector<vector<int> > w(n, vector<int>(n));
	rep(i, n) rep(j, n) {
		cin >> w[i][j];
		if (w[i][j]==0) w[i][j]=INF;
	}
	vector<vector<int> > dp(n, vector<int>((1<<n), INF));
	dp[0][1]=0;
	for (int i=1; i<(1<<n); i++) {
		for (int j=0; j<n; j++) {
			if (!(i&(1<<j))) continue;
			for (int k=0; k<n; k++) {
				if(i&(1<<k)) continue;
				dp[k][i|(1<<k)]=min(dp[k][i|(1<<k)], dp[j][i]+w[j][k]);
			}
		}
	}
	int res=INF;
	rep(i, n) res=min(res, dp[i][(1<<n)-1]+w[i][0]);
	cout << res;

	return 0;
}
