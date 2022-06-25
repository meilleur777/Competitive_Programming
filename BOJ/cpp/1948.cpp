#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> edge(n);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
	}
	int s, u;
	cin >> s >> u;
	s--, u--;
	ll inf=0x3f3f3f3f3f3f3f3f;
	vector<ll> dp(n, -1);
	function<ll(int)> sol=[&](int now) {
		if (now==u) return 0LL;
		ll& ret=dp[now];
		if (ret!=-1) return ret;
		ret=-1;
		for (auto nxt:edge[now]) {
			ret=max(ret, sol(nxt.first)+nxt.second);
		}
		return ret;
	};
	cout << sol(s) << '\n';
	set<intp> st;
	vector<bool> vis(n, false);
	function<void(int)> dfs=[&](int now) {
		vis[now]=true;
		if (now==u) return;
		for (auto nxt:edge[now]) {
			if (sol(now)==sol(nxt.first)+nxt.second) {
				st.insert({now, nxt.first});
				if (!vis[nxt.first]) dfs(nxt.first);
			}
		}
	};
	dfs(s);
	int ans=0;
	rep(i, n) {
		for (auto j:edge[i]) {
			ans+=st.find(make_pair(i, j.first))!=st.end();
		}
	}
	cout << ans << '\n';

	return 0;
}
