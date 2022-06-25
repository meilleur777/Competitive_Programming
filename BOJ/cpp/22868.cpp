#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	rep(i, n) sort(edge[i].begin(), edge[i].end());
	int s, e;
	cin >> s >> e;
	s--, e--;
	vector<int> vis(n, -1);
	vector<int> pi(n);
	vis[s]=0;
	pi[s]=-1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		if (now==e) break;
		for (auto nxt:edge[now]) {
			if (vis[nxt]==-1) {
				pi[nxt]=now;
				vis[nxt]=vis[now]+1;
				q.push(nxt);
			}
		}
	}
	while (!q.empty()) q.pop();
	int t=pi[e];
	int ans=vis[e];
	vis=vector<int>(n, -1);
	while (t!=s) {
		vis[t]=-2;
		t=pi[t];
	}
	vis[e]=0;
	q.push(e);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		if (now==s) break;
		for (auto nxt:edge[now]) {
			if (vis[nxt]==-1) {
				vis[nxt]=vis[now]+1;
				q.push(nxt);
			}
		}
	}
	cout << ans+vis[s];

	return 0;
}
