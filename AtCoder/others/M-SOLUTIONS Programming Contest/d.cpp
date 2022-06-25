#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> edge(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	ll sum=0;
	vector<ll> c(n);
	rep(i, n) {
		cin >> c[i];
		sum+=c[i];
	}
	sort(c.begin(), c.end());
	sum-=c.back();
	cout << sum << '\n';
	vector<int> ans(n);
	vector<bool> vis(n, false);
	int ptr=n-1;
	function<void(int)> dfs=[&](int now) {
		vis[now]=true;
		ans[now]=c[ptr];
		ptr--;
		for (auto i:edge[now]) {
			if (!vis[i]) dfs(i);
		}
	};
	dfs(0);
	rep(i, n) cout << ans[i] << ' ';

	return 0;
}
