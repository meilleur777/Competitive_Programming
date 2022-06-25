#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<intp>> edge(n);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	priority_queue<intp, vector<intp>, greater<intp>> pq;
	pq.push({0, 1});
	vector<int> dis(n, 0x3f3f3f3f);
	dis[1]=0;
	while (!pq.empty()) {
		auto [use, now]=pq.top();
		pq.pop();
		for (auto cand:edge[now]) {
			auto [nxt, cost]=cand;
			if (use+cost<dis[nxt]) {
				dis[nxt]=use+cost;
				pq.push({dis[nxt], nxt});
			}
		}
	}

	vector<int> dp(n, -1);
	dp[1]=1;
	function<int(int)> sol=[&](int now) {
		int& ret=dp[now];
		if (ret!=-1) return ret;
		ret=0;
		for (auto cand:edge[now]) {
			auto [nxt, cost]=cand;
			if (dis[nxt]<dis[now]) ret+=sol(nxt);
		}
		return ret;
	};
	cout << sol(0);

	return 0;
}
