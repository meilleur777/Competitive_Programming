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

vector<ll> dis;
vector<vector<intp> > edge;

void dfs(int now, ll las) {
	dis[now]=las;
	for (auto& [a, b]:edge[now]) {
		if (dis[a]!=-1) continue;
		dfs(a, las+b);
	}
}

int main() {
	init_code();

	int n;
	cin >> n;
	edge.resize(n);
	dis=vector<ll>(n, -1);
	rep(i, n-1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
	}
	dfs(0, 0);
	for (int i=0; i<n; i++) {
		cout << dis[i]%2 << '\n';
	}

	return 0;
}
