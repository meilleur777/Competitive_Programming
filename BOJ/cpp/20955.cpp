#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	vector<int> par(n);
	vector<intp> info(n, {1, 0}); //{# of node, # of edge};
	rep(i, n) par[i]=i;
	function<int(int)> find=[&](int x) {
		if (x==par[x]) return x;
		return par[x]=find(par[x]);
	};
	auto merge=[&](int a, int b) {
		a=find(a), b=find(b);
		par[a]=b;
		info[b].first+=info[a].first;
	};
	vector<bool> vis(n, false);
	function<void(int)> dfs=[&](int now) {
		vis[now]=true;
		for (auto nxt:edge[now]) {
			if (vis[nxt]) continue;
			merge(nxt, now);
			dfs(nxt);
		}
	};
	rep(i, n) if (!vis[i]) dfs(i);
	rep(i, n) info[find(i)].second+=(int)edge[i].size();
	set<int> st;
	rep(i, n) {
		info[i].second/=2;
		st.insert(find(i));
	}
	int ans=(int)st.size()-1;
	for (auto a:st) ans+=info[a].second-(info[a].first-1);	
	cout << ans;

	return 0;
}
