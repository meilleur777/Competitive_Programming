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

int main() {
	init_code();

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	queue<int> q;
	q.push(0);
	vector<int> ind(n, -1);
	ind[0]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (auto i:edge[now]) {
			if (ind[i]==-1) {
				ind[i]=now;
				q.push(i);
			}
		}
	}
	for (auto i:ind) {
		if (i==-1) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes\n";
	for (int i=1; i<n; i++) {
		cout << ind[i]+1 << '\n';
	}

	return 0;
}
