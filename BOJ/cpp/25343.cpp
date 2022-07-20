#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n, -1));
	rep(i, n) rep(j, n) cin >> a[i][j];

	function<int(int, int)> sol=[&](int y, int x) {
		if (!x && !y) return 1;
		int& ret=dp[y][x];
		if (ret!=-1) return ret;
		ret=1;
		for (int i=0; i<=y; i++) {
			for (int j=0; j<=x; j++) {
				if (i==y && j==x) continue;
				if (a[i][j]<a[y][x]) {
					ret=max(ret, sol(i, j)+1);
				}
			}
		}
		return ret;
	};

	int ans=1;
	rep(i, n) rep(j, n) ans=max(ans, sol(i, j));
	cout << ans;

	return 0;
}
