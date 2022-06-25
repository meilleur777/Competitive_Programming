#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> p(n);
	rep(i, n) cin >> p[i];

	ll inf=-1e16	;
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(3, inf)));
	function<ll(int, int, int)> sol=[&](int now, int flag, int used) {
		if (now==n) return 0LL;
		ll& ret=dp[now][flag][used];
		if (ret!=inf) return ret;

		if (flag) {
			ret=max(ret, sol(now+1, true, used)+p[now]*2);
			ret=max(ret, sol(now+1, false, used+1)+p[now]);
		}
		else {
			if (used<2) ret=max(ret, sol(now+1, true, used)+p[now]*2);
			ret=max(ret, sol(now+1, false, used)+p[now]);
		}
		return ret;
	};
	cout << sol(0, 0, 0);

	return 0;
}
