#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const ll mod=1e9+9;
const ll INF=6e10+1;

int n, m, x, y;
vector<ll> dis, use, dp;
vector<vector<pair<int, ll>>> edge;

ll sol(int now) {
	if (now==y) return 1;
	ll& ret=dp[now];
	if (ret!=-1) return ret;
	ret=0;
	for (auto i:edge[now]) {
		int nxt=i.first;
		ll wil=i.second;
		if (dis[nxt]==dis[now]+wil && use[nxt]==use[now]+1) {
			ret+=sol(nxt);
			ret%=mod;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> x >> y;
	x--, y--;
	edge.resize(n);
	rep(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edge[u].push_back({v, w});
	}
	priority_queue<pair<pair<ll, ll>, int>, vector<pair<pair<ll, ll>, int>>, greater<pair<pair<ll, ll>, int>>> pq;
	pq.push({{0, 0}, x});
	dis=vector<ll>(n, INF);
	use=vector<ll>(n, INF);
	dis[x]=0;
	use[x]=0;
	while (!pq.empty()) {
		int now=pq.top().second;
		ll cos=pq.top().first.first;
		ll cnt=pq.top().first.second;
		pq.pop();
		if (cos>dis[now]) continue;
		for (auto i:edge[now]) {
			int nxt=i.first;
			ll wil=i.second;
			if (dis[nxt]>cos+wil) {
				dis[nxt]=cos+wil;
				use[nxt]=cnt+1;
				pq.push({{dis[nxt], use[nxt]}, nxt});
			}
			else if (dis[nxt]==cos+wil) {
				if (use[nxt]>cnt+1) {
					use[nxt]=cnt+1;
					pq.push({{dis[nxt], use[nxt]}, nxt});
				}
			}
		}
	}
	if (dis[y]==INF) {
		cout << -1;
	}
	else {
		dp=vector<ll>(n, -1);
		cout << dis[y] << '\n' << use[y] << '\n' << sol(x);
	}

	return 0;
}
