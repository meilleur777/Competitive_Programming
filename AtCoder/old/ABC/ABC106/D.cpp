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

	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int> > dp(502, vector<int>(502, 0));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		dp[a][b]++;
	}
	for (int r=1; r<=500; r++) {
		for (int l=500; l>=0; l--) {
			dp[l][r]+=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1];
		}
	}
	rep(i, q) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}

	return 0;
}
