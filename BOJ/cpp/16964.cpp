#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<set<int>> edge(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].insert(b);
		edge[b].insert(a);
	}
	vector<int> ord(n);
	rep(i, n) {
		cin >> ord[i];
		ord[i]--;
	}
	if (ord[0]) {
		cout << 0;
		return 0;
	}

	vector<bool> vis(n, false);
	int num=1;
	function<void(int)> sol=[&](int now) {
		vis[now]=true;
		while (!edge[now].empty()) {
			if (edge[now].find(ord[num])==edge[now].end()) {
				cout << 0;
				exit(0);
			}

			int nxt=ord[num];
			edge[ord[num]].erase(now);
			edge[now].erase(ord[num]);
			num++;
			sol(nxt);
		}
	};
	sol(0);
	cout << 1;

	return 0;
}
