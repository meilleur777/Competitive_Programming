#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<intp>> edge(n);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
	}

	vector<priority_queue<int>> dis(n);
	priority_queue<intp, vector<intp>, greater<intp>> pq;
	pq.push({0, 0});
	dis[0].push(0);

	while (!pq.empty()) {
		auto [use, now]=pq.top();
		pq.pop();

		for (auto cand:edge[now]) {
			auto [nxt, cos]=cand;

			if (dis[nxt].size()<k) {
				dis[nxt].push(use+cos);
				pq.push({use+cos, nxt});
			}
			else {
				while (dis[nxt].size()>k) dis[nxt].pop();
				if (use+cos<=dis[nxt].top()) {
					dis[nxt].pop();
					dis[nxt].push(use+cos);
					pq.push({use+cos, nxt});	
				}
			}
		}
	}

	rep(i, n) {
		if (dis[i].size()<k) cout << -1 << '\n';
		else cout << dis[i].top() << '\n';
	}

	return 0;
}
