#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	vector<vector<int>> edge(n);

	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	vector<vector<int>> cost(n, vector<int>(2, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<2; j++) {
			cin >> cost[i][j];
		}
	}

	vector<bool> vis(n, false);
	function<long long(int, int)> sol=[&](int now, int past) {
		vis[now]=true;

		long long ret=cost[now][1-past];

		for (auto nxt:edge[now]) {
			if (vis[nxt]) continue;

			ret+=sol(nxt, 1-past);
		}

		return ret;
	};

	long long first=sol(0, 0);
	vis=vector<bool>(n, false);
	long long second=sol(0, 1);

	cout << min(first, second);

	return 0;
}
