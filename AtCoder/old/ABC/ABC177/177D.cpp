#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

vector<bool> vis;
vector<vector<int> > edges;

int DFS(int S) {
	vis[S] = true;
	int ret = 1;
	for (auto i : edges[S]) {
		if (!vis[i]) {
			ret += DFS(i);
		}
	}
	return ret;
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vis = vector<bool>(N + 1, false);
	edges = vector<vector<int> >(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);		
	}
	int ans = -1;
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			ans = max(ans, DFS(i));
		}
	}
	cout << ans;

	return 0;
}
