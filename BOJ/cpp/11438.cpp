#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int lgn=ceil(log2(n));
	vector<vector<int>> edge(n);
	rep(i, n-1) {	
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	vector<int> dep(n, -1);
	// par[a][b]::=a의 2^b번째 조상
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
			int k=par[j][i-1];
			if (k!=-1) par[j][i]=par[par[j][i-1]][i-1];
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (dep[a]<dep[b]) swap(a, b);
		int dif=dep[a]-dep[b];
		for (int i=0; i<=lgn; i++) {
			if (dif&(1<<i)) {
				a=par[a][i];
			}
		}
		if (a!=b) {
			for (int i=lgn; i>=0; i--) {
				if (par[a][i]!=par[b][i]) {
					a=par[a][i];
					b=par[b][i];
				}
			}
			a=par[a][0];
		}
		cout << a+1 << '\n';
	}

	return 0;
}
