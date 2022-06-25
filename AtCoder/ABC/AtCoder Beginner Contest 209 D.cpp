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

vector<vector<int> 	> edge;
vector<bool> vis;
vector<int> col;

void solve(int now, bool color) {
	vis[now]=true;
	col[now]=color;
	for (auto i:edge[now]) {
		if (!vis[i]) {
			solve(i, !color);
		}
	}
}

int main() {
	init_code();

	int n, q;
	cin >> n >> q;
	edge.resize(n+1);
	col.resize(n+1);
	vis=vector<bool>(n+1, false);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	solve(1, 0);
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (col[a]==col[b]) {
			cout << "Town\n";
		}
		else cout << "Road\n";
	}

	return 0;
}
