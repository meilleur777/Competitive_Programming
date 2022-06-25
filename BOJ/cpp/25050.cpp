#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> edge(n);
	vector<vector<ll>> cnt(n, vector<ll>(n, 0));
	vector<tuple<int, int, int>> v(m);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
		v[i]=make_tuple(i, a, b);
	}

	for (int s=0; s<n; s++) {
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({0, s});
		vector<ll> dis(n, 1e13);
		dis[s]=0;

		while (!pq.empty()) {
			auto [used, now]=pq.top();
			pq.pop();
			if (used>dis[now]) continue;
			for (auto cand:edge[now]) {
				auto [nxt, cost]=cand;
				if (used+cost<dis[nxt]) {
					dis[nxt]=used+cost;
					pq.push({dis[nxt], nxt});
				}
			}
		}

		function<int(int)> sol=[&](int now) {
			int ret=1;
			for (auto cand:edge[now]) {
				auto [nxt, cost]=cand;
				if (dis[now]+cost==dis[nxt]) {
					int t=sol(nxt);
					ret+=t;
					cnt[now][nxt]+=t;
				}
			}
			return ret;
		};
		sol(s);
	};
	sort(v.begin(), v.end(), [&](tuple<int, int, int> p, tuple<int, int, int> q){
		auto [a, b, c]=p;
		auto [d, e, f]=q;
		return cnt[b][c]<cnt[e][f];
	});
	auto [a, b, c]=v.back();
	int dd=a, ee=b, ff=c;
	int nxt=m-2;
	vector<int> ans;
	while (cnt[b][c]==cnt[ee][ff]) {
		ans.push_back(dd+1);
 		auto [d, e, f]=v[nxt];
 		dd=d, ee=e, ff=f;
		nxt--;
		if (nxt<-1) break;
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto i:ans) cout << i << ' ';

	return 0;
}
