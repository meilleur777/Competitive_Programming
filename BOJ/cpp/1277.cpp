#include <bits/stdc++.h>
using namespace std;

typedef pair<int, long double> par;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, w;
	cin >> n >> w;
	long double m;
	cin >> m;

	vector<pair<long long, long long>> point(n);
	for (int i=0; i<n; i++) {
		cin >> point[i].first >> point[i].second;
	}

	vector<vector<bool>> con(n, vector<bool>(n, false));
	while (w--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		con[a][b]=true;
		con[b][a]=true;
	}

	auto cmp=[](par p, par q) {
		return p.second>q.second;
	};
	priority_queue<par, vector<par>, decltype(cmp)> pq(cmp);

	const long double inf=1e18;
	vector<long double> dist(n, inf);
	dist[0]=0;
	pq.push({0, dist[0]});

	while (!pq.empty()) {
		int now=pq.top().first;
		long double used=pq.top().second;
		pq.pop();

		if (now==n-1) {
			long long ans=dist[n-1]*1000;
			cout << ans;
			break;
		}

		for (int nxt=0; nxt<n; nxt++) {
			if (nxt==now) continue;

			long double cost=sqrtl((point[now].first-point[nxt].first)*(point[now].first-point[nxt].first)
							+(point[now].second-point[nxt].second)*(point[now].second-point[nxt].second));
			if (con[now][nxt]==true) cost=0;

			if (cost>m) continue;

			if (used+cost<dist[nxt]) {
				dist[nxt]=used+cost;
				pq.push({nxt, dist[nxt]});
			}
		}
	}

	return 0;
}
