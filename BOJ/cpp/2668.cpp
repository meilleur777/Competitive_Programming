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

vector<int> res;
vector<bool> vis;
vector<int> edges;

void DFS(int now, int S) {
	if (vis[now]) {
		if (now == S) {
			res.push_back(now);
		}
	}
	else {
		vis[now] = true;
		DFS(edges[now], S);
	}
}


int main() {
	init_code();

	int N;
	cin >> N;
	edges.resize(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> edges[i];
	}
	for (int i = 1; i <= N; i++) {
		vis = vector<bool>(N+1, false);
		DFS(i, i);
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto i : res) {
		cout << i << '\n';
	}

	return 0;
}
