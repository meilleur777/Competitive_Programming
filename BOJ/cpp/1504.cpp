#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

const ll INF=2e8+1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, e;
	cin >> n >> e;
	vector<vector<pair<int, ll>>> edge(n);
	rep(i, e) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	auto dij=[&](int s, int u) {
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		vector<ll> dis(n, INF);
		dis[s]=0;
		pq.push({0, s});
		while (!pq.empty()) {
			int now=pq.top().second;
			int cos=pq.top().first;
			pq.pop();
			if (cos>dis[now]) continue;
			for (auto i:edge[now]) {
				int nxt=i.first;
				int wil=i.second;
				if (dis[nxt]>cos+wil) {
					dis[nxt]=cos+wil;
					pq.push({dis[nxt], nxt});
				}
			}
		}
		return dis[u];
	};
	int v1, v2;
	cin >> v1 >> v2;
	v1--, v2--;
	ll a=dij(0, v1)+dij(v1, v2)+dij(v2, n-1);
	ll b=dij(0, v2)+dij(v2, v1)+dij(v1, n-1);
	ll c=min(a, b);
	if (c>=INF) cout << -1;
	else cout << c;

	return 0;
}
