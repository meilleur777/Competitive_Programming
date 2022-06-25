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

	int n, k, r, s, p;
	cin >> n >> k >> r >> s >> p;
	string t;
	cin >> t;
	vector<int> l(n);
	rep(i, n) {
		if (t[i]=='s') l[i]=2;
		else if (t[i]=='p') l[i]=1;
		else l[i]=0;
	}
	int ans=0;
	vector<vector<int> > dp(3, vector<int>(n, 0));
	for (int i=0; i<n; i++) {
		int las=i-k;
		if (las>=0) {
			dp[0][i]=max(dp[1][i-k], dp[2][i-k]);
			dp[1][i]=max(dp[0][i-k], dp[2][i-k]);
			dp[2][i]=max(dp[0][i-k], dp[1][i-k]);
		}
		if (l[i]==0) dp[1][i]+=p;
		if (l[i]==1) dp[2][i]+=s;
		if (l[i]==2) dp[0][i]+=r;
	}
	for (int i=n-1; i>n-1-k; i--) {
		ans+=max({dp[0][i], dp[1][i], dp[2][i]});
	}
	cout << ans;

	return 0;
}
