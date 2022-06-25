#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	fast_io;
	cout << fixed;
	cout.precision(10);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<pair<int, ld> > > edges(N);
		rep(i, M) {
			int a, b;
			ld c;
			cin >> a >> b >> c;
			edges[a].push_back({b, c});
			edges[b].push_back({a, c});
		}
		priority_queue<pair<ld, int>, vector<pair<ld, int> >, greater<pair<ld, int> > > pq;
		vector<ld> dis(N, LDBL_MAX);
		dis[0] = 1.0;
		pq.push({1.0, 0});
		while (!pq.empty()) {
			pair<ld, int> now = pq.top();
			pq.pop();
			if (now.first > dis[now.second]) {
				continue;
			}
			for (auto i : edges[now.second]) {
				if (dis[i.first] > now.first*i.second) {
					dis[i.first] = now.first*i.second;
					pq.push({dis[i.first], i.first});
				}
			}
		}
		cout << dis[N-1] << '\n';
	}

	return 0;
}
