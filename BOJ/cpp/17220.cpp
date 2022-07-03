#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(26);
	vector<int> cnt(26, 0);
	rep(i, m) {
		char a, b;
		cin >> a >> b;
		edge[a-'A'].push_back(b-'A');
		cnt[b-'A']++;
	}
	vector<bool> ast(26, false);
	int p;
	cin >> p;
	while (p--) {
		char a;
		cin >> a;
		ast[a-'A']=true;
	}

	vector<bool> vis(26, false);
	function<void(int)> dfs=[&](int now) {
		if (ast[now]) return;
		vis[now]=true;
		for (auto nxt:edge[now]) {
			if (!vis[nxt]) dfs(nxt);
		}
	};
	int ans=0;
	for (int i=0; i<26; i++) {
		if (!cnt[i] && !ast[i]) {
			dfs(i);
			ans--;
		}
	}

	for (int i=0; i<26; i++) {
		ans+=vis[i];
	}
	cout << ans;

	return 0;
}
