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

map<intp, int> col;
vector<bool> vis;
vector<vector<int> > edges;

void solve(int now, int las) {
	vis[now]=true;
	int num=1;
	for (auto i:edges[now]) {
		if (num==las) num++;
		if (vis[i]) continue;
		int a=min(now, i), b=max(now, i);
		col[{a, b}]=num;
		solve(i, num);
		num++;
	}
}

int main() {
	init_code();

	int n;
	cin >> n;
	vis=vector<bool>(n, false);
	edges.resize(n);
	vector<intp> edge(n-1);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a>b) swap(a, b);
		edge[i]={a, b};
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	solve(1, -1);
	int tmp=-1;
	vector<int> res(n-1);
	rep(i, n-1) {
		res[i]=col[{edge[i].first, edge[i].second}];
		tmp=max(tmp, res[i]);
	}
	cout << tmp << '\n';
	for (auto i:res) cout << i << '\n';

	return 0;
}
