#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<string> brd(n);
	for (int i=0; i<n; i++) {
		cin >> brd[i];
	}	

	vector<vector<bool>> vis(n, vector<bool>(m, false));

	vector<int> x({0, 0, 1, -1});
	vector<int> y({1, -1, 0, 0});

	function<void(int, int)> dfs=[&](int i, int j) {
		vis[i][j]=true;

		int offset=((brd[i][j]=='-')?2:0);

		for (int d=offset; d<offset+2; d++) {
			int di=i+y[d];
			int dj=j+x[d];

			if (di<0 || di>=n || dj<0 || dj>=m) continue;
			if (vis[di][dj]) continue;
			if (brd[di][dj]!=brd[i][j]) continue;

			dfs(di, dj);
		}
	};

	int ans=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (vis[i][j]==false) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}
