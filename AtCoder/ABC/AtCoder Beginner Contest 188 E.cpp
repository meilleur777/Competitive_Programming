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

ll ans=-INF;
vector<ll> dp;
vector<vector<int>> edge;
vector<ll> a;

ll dfs(int now) {
	ll& ret=dp[now];
	if (ret!=-1) {
		// ans=max(ans, ret-a[now]);
		return ret;
	}
	ret=-INF;
	for (auto i:edge[now]) {
		ret=max(ret, dfs(i));
	}
	ans=max(ans, ret-a[now]);
	ret=max(ret, a[now]);
	// cout << now << ' ' << ret << '\n';
	return ret;
}

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	dp=vector<ll>(n, -1);
	a.resize(n);
	edge.resize(n);
	for (auto i:edge) {
		sort(i.begin(), i.end());
	}
	rep(i, n) cin >> a[i];
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		edge[x].push_back(y);
	}
	for (int i=0; i<n; i++) {
		dfs(i);
	}
	cout << ans;

	return 0;
}
