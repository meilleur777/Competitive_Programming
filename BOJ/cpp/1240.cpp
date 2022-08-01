#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<intp>> edge(n);
	rep(i, n-1) {
		int a, b, c;
		cin >> a >> b >> c; 
		a--, b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	while (m--) {
		vector<bool> vis(n, false);
		function<void(int, int, int)> dfs=[&](int now, int end, int cnt) {
			if (now==end) {
				cout << cnt << '\n';
				return;
			}
			for (auto i:edge[now]) {
				int nxt=i.first;
				int cst=i.second;
				if (!vis[nxt]) {
					vis[nxt]=true;
					dfs(nxt, end, cnt+cst);
				}
			}
		};
		int a, b;
		cin >> a >> b;
		a--, b--;
		vis[a]=true;	
		dfs(a, b, 0);
	}

	return 0;
}
