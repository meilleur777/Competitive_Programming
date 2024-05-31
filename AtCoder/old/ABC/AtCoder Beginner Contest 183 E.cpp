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

const ll mod=1e9+7;
const ll INF=0x3F3F3F3F;

int main() {
	init_code();

	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<ll>> dp(h+1, vector<ll>(w+1, 0));
	vector<vector<ll>> row(h+1, vector<ll>(w+1, 0));
	vector<vector<ll>> col(h+1, vector<ll>(w+1, 0));
	vector<vector<ll>> dig(h+1, vector<ll>(w+1, 0));
	dp[1][1]=1;
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			if (s[i-1][j-1]=='#') continue;
			row[i][j]=(row[i-1][j]+dp[i-1][j])%mod;
			col[i][j]=(col[i][j-1]+dp[i][j-1])%mod;
			dig[i][j]=(dig[i-1][j-1]+dp[i-1][j-1])%mod;
			dp[i][j]+=(row[i][j]+col[i][j]+dig[i][j])%mod;
		}
	}	
	cout << dp[h][w];

	return 0;
}
