#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll mod=1e9+9;
	vector<ll> dp(1e6+1, -1);
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	function<ll(int)> sol=[&](int now) {
		ll& ret=dp[now];
		if (ret!=-1) return ret;
		ret=(sol(now-1)+sol(now-2)+sol(now-3))%mod;
		return ret;
	};

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << sol(n) << '\n';
	}

	return 0;
}
