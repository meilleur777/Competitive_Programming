#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	vector<vector<intp>> edge(n);
	rep(i, n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	vector<int> dis(n, -1);
	int lgn=ceil(log2(n));
	vector<vector<int>> par(n, vector<int>(lgn+1, -1));
	function<void(int)> dfs=[&](int now) {
		for (auto i:edge[now]) {
			int nxt=i.first;
			int cos=i.second;
			if (dis[nxt]!=-1) continue;
			par[nxt][0]=now;
			dis[nxt]=dis[now]+cos;
			dfs(nxt);
		}
	};
	dis[0]=0;
	dfs(0);
	for (int i=1; i<=lgn; i++) {
		for (int j=0; j<n; j++) {
			int nxt=par[j][i-1];
			if (nxt!=-1) par[j][i]=par[nxt][i-1];
		}
	}
	rep(i, n) {
		int now=i;
		for (int j=lgn; j>=0; j--) {
			int nxt=par[now][j];
			if (nxt!=-1 && dis[now]-dis[nxt]<=v[i]) {
				v[i]-=dis[now]-dis[nxt];
				now=nxt;
			}
		}
		cout << now+1 << '\n';
	}

	return 0;
}
