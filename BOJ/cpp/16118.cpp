#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<intp>> edge(n);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		c*=2;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, 0});
	vector<ll> dis(n, (ll)4e10+1);
	dis[0]=0;
	while (!pq.empty()) {
		int now=pq.top().second;
		ll use=pq.top().first;
		pq.pop();
		if (use>dis[now]) continue;
		for (auto i:edge[now]) {
			int nxt=i.first;
			ll cos=i.second;
			if (dis[nxt]>cos+use) {
				dis[nxt]=cos+use;
				pq.push({dis[nxt], nxt});
			}
		}
	}
	priority_queue<pair<ll, pair<int, bool>>, vector<pair<ll, pair<int, bool>>>, greater<pair<ll, pair<int, bool>>>> pq2;
	vector<vector<ll>> dis2(2, vector<ll>(n, (ll)4e10+1));
	pq2.push({0, {0, true}});
	dis2[1][0]=0;
	while (!pq2.empty()) {
		int now=pq2.top().second.first;
		bool flag=pq2.top().second.second;
		ll use=pq2.top().first;
		pq2.pop();
		if (use>dis2[flag][now]) continue;
		for (auto i:edge[now]) {
			int nxt=i.first;
			ll cos=i.second;
			if (flag) cos/=2;
			else cos*=2; 
			if (dis2[!flag][nxt]>use+cos) {
				dis2[!flag][nxt]=use+cos;
				pq2.push({dis2[!flag][nxt], {nxt, !flag}});
			}
		}
	}
	int ans=0;
	for (int i=0; i<n; i++) {
		ans+=(dis[i]<min(dis2[0][i], dis2[1][i]));
	}
	cout << ans;

	return 0;
}
