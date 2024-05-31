#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

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

vector<int> vis;
vector<vector<intp> > edges;

void DFS(int S) {
	for (intp i : edges[S]) {
		if (vis[i.first] == -INT_MAX) {
			vis[i.first] = vis[S]+i.second;
			DFS(i.first);
		}
		else {
			if (vis[i.first] != vis[S]+i.second) {
				cout << "No";
				exit(0);
			}
		}
	}
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	edges = vector<vector<intp> >(N+1);
	vis = vector<int>(N+1, -INT_MAX);
	rep(i, M) {
		int l, r, d;
		cin >> l >> r >> d;
		edges[l].push_back({r, d});
		edges[r].push_back({l, -d});
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i] == -INT_MAX) {
			vis[i] = 0;
			DFS(i);
		}
	}
	cout << "Yes";

	return 0;
}
