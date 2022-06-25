#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	fast_io;

	int C;
	cin >> C;
	while (C--) {
		int V, E, n, m;
		cin >> V >> E >> n >> m;
		vector<vector<intp> > edges(V+1);
		rep(i, E) {
			int a, b, c;
			cin >> a >> b >> c;
			edges[a].push_back({b, c});
			edges[b].push_back({a, c});
		}
		vector<int> F(n), S(m);
		rep(i, n) cin >> F[i];
		rep(i, m) cin >> S[i];
		priority_queue<intp, vector<intp>, greater<intp> > pq;
		vector<int> dis(V+1, INT_MAX);
		rep(i, m) {
			dis[S[i]] = 0;
			pq.push({0, S[i]});
		}
		while (!pq.empty()) {
			intp now = pq.top();
			pq.pop();
			if (now.first > dis[now.second]) {
				continue;
			}
			for (auto i : edges[now.second]) {
				if (dis[i.first] > now.first+i.second) {
					dis[i.first] = now.first+i.second;
					pq.push({dis[i.first], i.first});
				}
			}
		}
		int ans = 0;
		rep(i, n) {
			ans += dis[F[i]];
		}	
		cout << ans << '\n';
	}

	return 0;
}
