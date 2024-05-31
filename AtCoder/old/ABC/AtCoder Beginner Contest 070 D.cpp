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
const int INF=0x3F3F3F3F;

vector<ll> dep;
vector<bool> vis;
vector<vector<pair<int, ll> > > edge;

void sol(int now, ll sum) {
	dep[now]=sum;
	vis[now]=true;
	for (auto [a, b]:edge[now]) {
		if (vis[a]) continue;
		sol(a, sum+b);
	}
}

int main() {
	init_code();

	int n;
	cin >> n;
	dep.resize(n);
	edge.resize(n);
	vis=vector<bool>(n, false);
	rep(i, n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	int q, k;
	cin >> q >> k;
	k--;
	sol(k, 0);
	rep(i, q) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << dep[x]+dep[y] << '\n';
	}

	return 0;
}
