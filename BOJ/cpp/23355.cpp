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
	rep(i, n-1) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	vector<int> dep(n, -1);
	vector<vector<int>> par(n, vector<int>(lgn+1, -1));
	function<void(int)> dfs=[&](int now) {
		for (auto nxt:edge[now]) {
			if (dep[nxt]==-1) {
				par[nxt][0]=now;
				dep[nxt]=dep[now]+1;
				dfs(nxt);
			}
		}
	};
	dep[0]=0;
	dfs(0);
	for (int i=1; i<=lgn; i++) {
		for (int j=0; j<n; j++) {
			if (par[j][i-1]!=-1) par[j][i]=par[par[j][i-1]][i-1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a;
		cin >> a;
		auto lca=[&](int u, int v) {
			if (dep[u]<dep[v]) swap(u, v);
			int dif=dep[u]-dep[v];
			for (int i=0; i<=lgn; i++) {
				if (dif&(1<<i)) {
					u=par[u][i];
				}
			}
			if (u==v) return u;
			for (int i=lgn; i>=0; i--) {
				if (par[u][i]!=par[v][i]) {
					u=par[u][i];
					v=par[v][i];
				}
			}
			u=par[u][0];
			return u;
		};
		auto chk=[&](int u, int v, int p) {
			int lcaup=lca(u, p);
			int lcavp=lca(v, p);
			int lcauv=lca(u, v);
			bool case1=(lcauv==p);
			bool case2=(lcaup==p && lcavp==lcauv);
			bool case3=(lcavp==p && lcaup==lcauv);
			return case1 || case2 || case3;
		};
		if (a==1) {
			int x, y, z;
			cin >> x >> y >> z;
			x--, y--, z--;
			if (chk(x, y, z)) cout << "NO\n";
			else cout << "YES\n";
		}
		else {
			int x, y, z, w;
			cin >> x >> y >> z >> w;
			x--, y--, z--, w--;
			if (chk(x, y, z) && chk(x, y, w)) cout << "NO\n";
			else cout << "YES\n";
		}
	}

	return 0;
}
