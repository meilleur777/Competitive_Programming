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

int N;
vector<vector<int> > edges;

/*return score of S*/
int BFS(int S) {
	vector<int> vis(N + 1, -1);
	queue<int> q;
	q.push(S);
	vis[S] = 0;
	int ret = -1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		ret = max(ret, vis[now]);

		for (int i : edges[now]) {
			if (vis[i] == -1) {
				vis[i] = vis[now] + 1;
				q.push(i);
			}
		}
	}
	return ret;
}

int main() {
	init_code();

	cin >> N;

	edges.resize(N + 1);
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1) break;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int res = INT_MAX;
	vector<int> val(N + 1);
	for (int i = 1; i <= N; i++) {
		val[i] = BFS(i);
		res = min(res, val[i]);
	}
	vector<int> resv;
	for (int i = 1; i <= N; i++) {
		if (res == val[i]) {
			resv.push_back(i);
		}
	}

	cout << res << ' ' << resv.size() << '\n';
	for (auto i : resv) {
		cout << i << ' ';
	}
	cout << '\n';
}
