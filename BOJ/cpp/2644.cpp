#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, a, b, m;
	cin >> n >> a >> b >> m;
	a--, b--;	
	vector<vector<int>> edge(n);
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	vector<int> vis(n, -1);
	vis[a]=0;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (auto nxt:edge[now]) {
			if (vis[nxt]!=-1) continue;
			vis[nxt]=vis[now]+1;
			q.push(nxt);
		}
	}
	if (vis[b]==-1) cout << -1;
	else cout << vis[b];

	return 0;
}
