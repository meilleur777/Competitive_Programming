#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, k, x;
	cin >> n >> m >> k >> x;
	x--;
	vector<vector<int>> edge(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
	}
	vector<int> dis(n, -1);
	queue<int> q;
	q.push(x);
	dis[x]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		if (dis[now]>k) continue;
		for (auto nxt:edge[now]) {
			if (dis[nxt]==-1) {
				dis[nxt]=dis[now]+1;
				q.push(nxt);
			}
		}
	}
	vector<int> ans;
	rep(i, n) if (dis[i]==k) ans.push_back(i+1);
	if (ans.empty()) cout << -1;
	else for (auto i:ans) cout << i << '\n';

	return 0;
}
