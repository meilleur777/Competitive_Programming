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

vector<ll> val;
vector<vector<int> > edge, child;
vector<bool> vis;

void maketree(int now) {
	vis[now]=true;
	for (auto i:edge[now]) {
		if (!vis[i]) {
			child[now].push_back(i);
			maketree(i);
		}
	}
}

void solve(int now, ll sum) {
	val[now]+=sum;
	for (auto i:child[now]) {
		solve(i, val[now]);
	}
}

int main() {
	init_code();

	int n, q;
	cin >> n >> q;
	edge.resize(n+1);
	child.resize(n+1);
	vis=vector<bool>(n+1, false);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}	
	maketree(1);
	val=vector<ll>(n+1, 0);
	rep(i, q) {
		int p, x;
		cin >> p >> x;
		val[p]+=x;
	}
	solve(1, 0);
	for (int i=1; i<=n; i++) {
		cout << val[i] << ' ';
	}

	return 0;
}
