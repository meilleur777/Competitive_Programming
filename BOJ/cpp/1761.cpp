#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> edge(n);
	int lgn=ceil(log2(n));
	map<intp, ll> mp;	
	rep(i, n-1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		mp[{min(u, v), max(u, v)}]=w;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	vector<vector<int>> par(n, vector<int>(lgn+1, -1));
	vector<vector<ll>> wei(n, vector<ll>(lgn+1, 0));
	vector<int> dep(n, -1);
	function<void(int)> dfs=[&](int now) {
		for (auto nxt:edge[now]) {
			if (dep[nxt]==-1) {
				dep[nxt]=dep[now]+1;
				par[nxt][0]=now;
				wei[nxt][0]=mp[{min(nxt, now), max(nxt, now)}];
				dfs(nxt);
			}
		}
	};
	dep[0]=0;
	dfs(0);
	for (int i=1; i<=lgn; i++) {
		for (int j=0; j<n; j++) {
			int t=par[j][i-1];
			if (t!=-1) {
				par[j][i]=par[t][i-1];
				wei[j][i]=wei[j][i-1]+wei[t][i-1];
			}
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (dep[u]<dep[v]) swap(u, v);
		int uu=u, vv=v;
		int dif=dep[u]-dep[v];
		for (int i=0; i<=lgn; i++) {
			if (dif&(1<<i)) {
				uu=par[uu][i];
			}
		}
		if (uu!=vv) {
			for (int i=lgn; i>=0; i--) {
				if (par[uu][i]!=par[vv][i]) {
					uu=par[uu][i];
					vv=par[vv][i];
				}
			}
			uu=par[uu][0];
		}
		int ans=0;
		dif=dep[u]-dep[uu];
		for (int i=0; i<=lgn; i++) {
			if (dif&(1<<i)) {
				ans+=wei[u][i];
				u=par[u][i];
			}
		}
		dif=dep[v]-dep[uu];
		for (int i=0; i<=lgn; i++) {
			if (dif&(1<<i)) {
				ans+=wei[v][i];
				v=par[v][i];
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
