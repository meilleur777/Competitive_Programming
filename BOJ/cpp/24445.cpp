#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	r--;
	vector<vector<int>> edge(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	rep(i, n) sort(edge[i].begin(), edge[i].end(), greater<int>());
	vector<int> vis(n, 0);
	vis[r]=1;
	queue<int> q;
	q.push(r);
	int cnt=2;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (auto nxt:edge[now]) {
			if (vis[nxt]) continue;
			vis[nxt]=cnt++;
			q.push(nxt);
		}
	}
	rep(i, n) cout << vis[i] << '\n';

	return 0;
}
