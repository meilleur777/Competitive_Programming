#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> edge(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	vector<vector<int>> child(n);
	vector<bool> vis(n, false);
	function<void(int)> dfs=[&](int now) {
		vis[now]=true;
		for (auto nxt:edge[now]) {
			if (vis[nxt]) continue;
			child[now].push_back(nxt);
			dfs(nxt);
		}
	};
	dfs(0);
	int q;
	cin >> q;
	while (q--) {
		int t, k;
		cin >> t >> k;
		k--;
		if (t==1) {
			if (k==0) {
				if (child[0].size()==1) cout << "no\n";
				else cout << "yes\n";
			}
			else {
				if (child[k].empty()) cout << "no\n";
				else cout << "yes\n";
			}
		}
		else cout << "yes\n";
	}

	return 0;
}
