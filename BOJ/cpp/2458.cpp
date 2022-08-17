#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> from(n), to(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		from[a].push_back(b);
		to[b].push_back(a);
	}

	vector<int> cnt(n, 0);
	vector<bool> vis(n, false);
	function<void(int)> totop=[&](int now) {
		cnt[now]++;
		vis[now]=true;
		for (auto nxt:from[now]) {
			if (vis[nxt]) continue;
			totop(nxt);
		}
	};
	rep(i, n) {
		totop(i);
		vis=vector<bool>(n, false);
		cnt[i]--;
	}

	function<void(int)> tobot=[&](int now) {
		cnt[now]++;
		vis[now]=true;
		for (auto nxt:to[now]) {
			if (vis[nxt]) continue;
			tobot(nxt);
		}
	};
	rep(i, n) {
		tobot(i);
		vis=vector<bool>(n, false);
		cnt[i]--;
	}

	int ans=0;
	for (auto i:cnt) {
		ans+=(i==n-1);
	}
	cout << ans;

	return 0;
}
