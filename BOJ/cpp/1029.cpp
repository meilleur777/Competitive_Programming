#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<short>> a(n, vector<short>(n));
	rep(i, n) {
		string s;
		cin >> s;
		rep(j, n) a[i][j]=s[j]-'0';
	}
	a[0][0]=0;
	vector<vector<vector<short>>> dp(n, vector<vector<short>>(n, vector<short>((1<<n), -1)));
	function<short(short, short, short)> sol=[&](short now, short was, short sta) {
		short& ret=dp[now][was][sta];
		if (ret!=-1) return ret;
		ret=1;
		short use=a[was][now];
		rep(nxt, n) {
			if (sta&(1<<nxt)) continue;
			if (use<=a[now][nxt]) ret=max(ret, (short)(sol(nxt, now, (sta|(1<<nxt)))+1));
		}
		return ret;
	};
	cout << sol(0, 0, 1);

	return 0;
}
