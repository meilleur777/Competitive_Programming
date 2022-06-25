#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> edge(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	vector<set<int>> st(n);
	vector<bool> vis(n, false);
	function<void(int)> maketree=[&](int now) {
		vis[now]=true;
		for (auto nxt:edge[now]) {
			if (vis[nxt]) continue;
			st[now].insert(nxt);
			maketree(nxt);
		}
	};
	maketree(0);

	bool flag=true;
	int one;
	cin >> one;
	if (one!=1) flag=false;

	queue<int> q;
	rep(i, st[0].size()) q.push(0);

	rep(i, n-1) {
		int a;
		cin >> a;
		a--;
		while (!q.empty() && st[q.front()].empty()) q.pop();
		if (q.empty() || st[q.front()].find(a)==st[q.front()].end()) {
			flag=false;
		}
		else {
			st[q.front()].erase(a);
			q.pop();
			int size=st[a].size();
			rep(i, size) q.push(a);
		}
	}

	cout << flag;

	return 0;
}
