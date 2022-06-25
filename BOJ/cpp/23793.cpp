#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<intp>> edge(n);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
	}
	int x, y, z;
	cin >> x >> y >> z;
	x--, y--, z--;
	auto dij=[&](int s, int u, bool flag) {
		priority_queue<intp, vector<intp>, greater<intp>> pq;
		vector<int> dis(n, (int)2e9+1);
		pq.push({0, s});
		dis[s]=0;
		while (!pq.empty()) {
			int now=pq.top().second;
			int use=pq.top().first;
			pq.pop();
			if (use>dis[now]) continue;
			for (auto www:edge[now]) {
				int nxt=www.first;
				int cos=www.second;
				if (nxt==y && flag) continue;
				if (dis[nxt]>use+cos) {
					dis[nxt]=use+cos;
					pq.push({dis[nxt], nxt});
				}
			}
		}
		if (dis[u]>2e9) return -1;
		return dis[u];
	};
	int xtoy=dij(x, y, false), ytoz=dij(y, z, false);
	if (xtoy==-1 || ytoz==-1) cout << -1 << ' ';
	else cout << xtoy+ytoz << ' ';
	int xtoz=dij(x, z, true);
	cout << xtoz;

	return 0;
}
