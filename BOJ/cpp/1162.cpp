#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const ll INF=0x3F3F3F3F3F3F3F3F;

int main() {
	init_code();

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, ll> > > edge(n+1);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
		edge[a].push_back({b, 0});
		edge[b].push_back({a, 0});
	}
	vector<vector<ll> > dis(k+1, vector<ll>(n+1, INF));
	dis[0][1]=0;
	priority_queue<pair<ll, intp>, vector<pair<ll, intp> >, greater<pair<ll, intp> > > pq;
	pq.push({dis[0][1], {1, 0}});
	while (!pq.empty()) {
		ll a=pq.top().first;
		ll b=pq.top().second.first;
		ll c=pq.top().second.second;
		pq.pop();
		if (a>dis[c][b]) continue;
		for (auto i:edge[b]) {
			int e=i.first;
			int d=i.second;
			if (d==0) {
				if (c<k && dis[c+1][e]>a) {
					dis[c+1][e]=a;
					pq.push({dis[c+1][e], {e, c+1}});
				}
			}
			else {
				if (dis[c][e]>a+d) {
					dis[c][e]=a+d;
					pq.push({dis[c][e], {e, c}});
				}
			}
		}
	}
	ll res=LLONG_MAX;
	for (int i=0; i<=k; i++) {
		res=min(res, dis[i][n]);
	}
	cout << res;

	return 0;
}
