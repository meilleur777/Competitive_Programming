#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int INF=0x3f3f3f3f;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	map<intp, int> mp;
	vector<vector<int>> edge(n);
	rep(i, n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
		mp[{min(a, b), max(a, b)}]=c;
	}
	int lgn=ceil(log2(n));
	vector<int> dep(n, -1);
	vector<vector<int>> par(n, vector<int>(lgn+1, -1));
	vector<vector<int>> mn(n, vector<int>(lgn+1, INF));
	vector<vector<int>> mx(n, vector<int>(lgn+1, -1));
	function<void(int)> dfs=[&](int now) {
		for (auto nxt:edge[now]) {
			if (dep[nxt]==-1) {
				par[nxt][0]=now;
				mn[nxt][0]=mp[{min(nxt, now), max(nxt, now)}];
				mx[nxt][0]=mp[{min(nxt, now), max(nxt, now)}];	
				dep[nxt]=dep[now]+1;
				dfs(nxt);
			}
		}
	};
	dep[0]=0;
	dfs(0);
	for (int i=1; i<=lgn; i++) {
		for (int j=0; j<n; j++) {
			if (par[j][i-1]!=-1) {
				par[j][i]=par[par[j][i-1]][i-1];
				mn[j][i]=min(mn[j][i-1], mn[par[j][i-1]][i-1]);
				mx[j][i]=max(mx[j][i-1], mx[par[j][i-1]][i-1]);
			}
		}
	}
	int k;
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (dep[a]<dep[b]) swap(a, b);
		int dif=dep[a]-dep[b];
		int aa=a, bb=b;
		for (int i=0; i<=lgn; i++) {
			if (dif&(1<<i)) {
				aa=par[aa][i];
			}
		}
		if (aa!=bb) {
			for (int i=lgn; i>=0; i--) {
				if (par[aa][i]!=par[bb][i]) {
					aa=par[aa][i], bb=par[bb][i];
				}
			}
			aa=par[aa][0];
		}	
		int amn=INF, amx=-1;
		dif=dep[a]-dep[aa];
		for (int i=0; i<=lgn; i++) {
			if (dif&(1<<i)) {
				amn=min(amn, mn[a][i]);
				amx=max(amx, mx[a][i]);
				a=par[a][i];
			}
		}
		dif=dep[b]-dep[aa];
		for (int i=0; i<=lgn; i++) {
			if (dif&(1<<i)) {
				amn=min(amn, mn[b][i]);
				amx=max(amx, mx[b][i]);
				b=par[b][i];
			}
		}
		cout << amn << ' ' << amx << '\n';
	}

	return 0;
}
