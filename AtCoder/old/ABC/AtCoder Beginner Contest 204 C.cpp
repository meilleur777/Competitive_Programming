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

vector<bool> vis;
vector<vector<int>> edge;

int dfs(int now) {
	vis[now]=true;
	int ret=1;
	for (auto i:edge[now]) {
		if (!vis[i]) ret+=dfs(i);
	}
	return ret;
}

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	edge.resize(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
	}
	int ans=0;
	rep(i, n) {
		vis=vector<bool>(n, false);
		ans+=dfs(i);
	}
	cout << ans;

	return 0;
}
