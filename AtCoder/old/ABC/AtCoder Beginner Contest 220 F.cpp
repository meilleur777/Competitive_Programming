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

int n;
vector<ll> ans;
vector<ll> dis;
vector<int> siz;
vector<bool> vis;
vector<vector<int>> edge;

void root(int now, ll d) {
	vis[now]=true;
	dis[now]=d;
	siz[now]++;
	for (auto i:edge[now]) {
		if (vis[i]) continue;
		root(i, dis[now]+1);
		siz[now]+=siz[i];
	}
}

void sol(int now, int par) {
	if (par!=-1) {
		ans[now]=ans[par]+n-2*siz[now];
	}
	for (auto i:edge[now]) {
		if (i==par) continue;
		sol(i, now);
	}
}

int main() {
	init_code();

	cin >> n;
	ans=vector<ll>(n, 0);
	siz=vector<int>(n, 0);
	edge.resize(n);
	rep(i, n-1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dis.resize(n);
	vis=vector<bool>(n, false);
	root(0, 0);
	for (auto i:dis) ans[0]+=i;
	sol(0, -1);
	for (auto i:ans) cout << i << '\n';

	return 0;
}
