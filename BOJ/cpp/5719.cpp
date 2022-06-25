#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

ll INF=0x3f3f3f3f;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		int s, d;
		cin >> s >> d;
		vector<vector<ll>> edge(n, vector<ll>(n, INF));
		rep(i, m) {
			int a, b, c;
			cin >> a >> b >> c;
			edge[a][b]=c;
		}
		vector<ll> dis(n, INF);
		auto dij=[&](int q, int u) {
			dis[q]=0;
			priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
			pq.push({0, q});
			while (!pq.empty()) {
				int now=pq.top().second;
				ll use=pq.top().first;
				pq.pop();
				if (dis[now]<use) continue;
				for (int i=0; i<n; i++) {
					if (dis[i]>use+edge[now][i]) {
						dis[i]=use+edge[now][i];
						pq.push({dis[i], i});
					}
				}
			}
			return dis[u];
		};
		if (dij(s, d)>=1e7+1) {
			cout << -1 << '\n';
			continue;
		}
		vector<bool> vis(n, false);
		queue<int> q;
		q.push(d);
		vis[d]=true;
		while (!q.empty()) {
			int now=q.front();
			q.pop();
			for (int i=0; i<n; i++) {
				if (dis[i]+edge[i][now]==dis[now]) {
					edge[i][now]=INF;
					if (!vis[i]) {
						vis[i]=true;
						q.push(i);
					}
				}
			}
		}
		dis=vector<ll>(n, INF);
		dis[s]=0;
		ll res=dij(s, d);
		if (res>=1e7+1) cout << -1 << '\n';
		else cout << res << '\n';
	}

	return 0;
}
