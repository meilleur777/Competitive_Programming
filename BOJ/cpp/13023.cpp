#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	while (m--) {
		int a, b;
		cin >> a >> b ;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	bool flag;
	vector<bool> vis;
	function<void(int, int)> dfs=[&](int now, int cnt) {
		if (cnt>=4) {
			flag=true;
			return;
		}
		for (auto nxt:edge[now]) {
			if (!vis[nxt]) {
				vis[nxt]=true;
				dfs(nxt, cnt+1);
				vis[nxt]=false;
			}
		}
	};
	rep(i, n) {
		flag=false;
		vis=vector<bool>(n, false);
		vis[i]=true;
		dfs(i, 0);
		if (flag) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
