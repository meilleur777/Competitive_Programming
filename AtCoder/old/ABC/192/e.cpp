#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const ll INF=0x3F3F3F3F3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, x, y;
	cin >> n >> m >> x >> y;
	x--, y--;
	vector<vector<pair<pair<ll, ll>, ll>>> edge(n);
	rep(i, m) {
		int a, b, t, k;
		cin >> a >> b >> t >> k;
		a--, b--;
		edge[a].push_back({{b, t}, k});
		edge[b].push_back({{a, t}, k});
	}
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, x});
	vector<ll> dis(n, INF);
	dis[x]=0;
	while (!pq.empty()) {
		int now=pq.top().second;
		ll time=pq.top().first;
		pq.pop();
		if (time>dis[now]) continue;
		if (now==y) break;
		for (auto i:edge[now]) {
			int nxt=i.first.first;
			int cos=i.first.second;
			int k=i.second;
			if (time%k==0) {
				if (dis[nxt]>cos+time) {
					dis[nxt]=cos+time;
					pq.push({dis[nxt], nxt});
				}
			}
			else {
				if (dis[nxt]>cos+time+k-time%k) {
					dis[nxt]=cos+time+k-time%k;
					pq.push({dis[nxt], nxt});
				}
			}
		}
	}
	if (dis[y]>=INF) cout << -1;
	else cout << dis[y];

	return 0;
}
