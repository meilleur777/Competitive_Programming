#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vector<vector<intp> > edges(N+1);
	rep(i, M) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({b, c});
	}
	for (int i = 1; i <= N; i++) {
		priority_queue<intp, vector<intp>, greater<intp> > pq;
		vector<int> dist(N+1, INT_MAX);
		pq.push({0, i});
		while (!pq.empty()) {
			intp now = pq.top();
			pq.pop();
			if (dist[now.second] < now.first) {
				continue;
			}
			for (auto j : edges[now.second]) {
				if (dist[j.first] > now.first+j.second) {
					dist[j.first] = now.first+j.second;
					pq.push({dist[j.first], j.first});
				}
			}
		}
		if (dist[i] == INT_MAX) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}

	return 0;
}
