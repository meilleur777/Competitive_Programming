#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	auto pos=[&](int st, int ed) {
		if (a[0][0]<st || a[0][0]>ed) return false;
		queue<intp> q;
		q.push({0, 0});
		vector<vector<bool>> vis(n, vector<bool>(n, false));
		vis[0][0]=true;
		while (!q.empty()) {
			int y=q.front().first;
			int x=q.front().second;
			q.pop();
			for (int d=0; d<4; d++) {
				int ny=y+dy[d];
				int nx=x+dx[d];
				if (ny>=n || ny<0 || nx>=n || nx<0) continue;
				if (vis[ny][nx]) continue;
				if (a[ny][nx]<st || a[ny][nx]>ed) continue;
				q.push({ny, nx});
				vis[ny][nx]=true;
			}
		}
		if (vis[n-1][n-1]) return true;
		return false;
	};
	int left=0, right=200;
	int ans=200;
	while (left<=right) {
		int mid=(left+right)/2;
		bool flag=false;
		for (int st=0; st+mid<=200; st++) {
			if (pos(st, st+mid)) {
				flag=true;
				break;
			}
		}
		if (flag) {
			ans=mid;
			right=mid-1;
		}
		else left=mid+1;
	}
	cout << ans;

	return 0;
}
