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

int num=1;
vector<int> vis;
vector<intp> ans;
vector<vector<int> > edge;

int dfs(int now, int par) {
	vis[now]=num;
	num++;
	int ret=vis[now];
	for (auto i:edge[now]) {
		if (i==par) continue;
		if (vis[i]==0) {
			int tmp=dfs(i, now);
			if (tmp>vis[now]) {
				ans.push_back({now, i});
				if (now>i) swap(ans.back().first, ans.back().second);
			}
			ret=min(ret, tmp);
		}
		else {
			ret=min(ret, vis[i]);
		}
	}
	return ret;
}

int main() {
	init_code();

	int v, e;
	cin >> v >> e;
	vis=vector<int>(v+1, 0);
	edge.resize(v+1);
	rep(i, e) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i=1; i<=v; i++) {
		if (vis[i]==0) dfs(i, -1);
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto [a, b]:ans) {
		cout << a << ' ' << b << '\n';
	}

	return 0;
}
