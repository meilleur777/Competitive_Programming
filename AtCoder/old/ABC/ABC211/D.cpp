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

const int mod = 1e9 + 7;

vector<vector<int> > edges;

int main() {
	init_code();

	int N, M;
	cin >> N >> M;

	edges.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	vector<int> vis(N + 1, -1), cnt(N + 1, 0);
	vis[1] = 0;
	cnt[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto i : edges[now]) {
			if (vis[i] == -1) {
				vis[i] = vis[now] + 1;
				cnt[i] += cnt[now];
				cnt[i] %= mod;
				q.push(i);
			}
			else if (vis[i] == vis[now] + 1) {
				cnt[i] += cnt[now];
				cnt[i] %= mod;
			}
		}
	} 

	cout << cnt[N];
}
