#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, c, e;
	cin >> n >> c >> e;
	int now=0;
	vector<string> mp(n, string(n, '0'));
	int t=c;
	while (t>0) {
		for (int i=0; i<=now; i++) {
			if (i>=n || i<0 || now-i>=n || now-i<0) continue;
			mp[i][now-i]='1';	
			t--;
			if (t==0) break;
		}
		now++;
	}
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	int cnt=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (mp[i][j]!='0') continue;
			bool flag=false;
			for (int d=0; d<4; d++) {
				int ny=i+dy[d];
				int nx=j+dx[d];
				if (ny>=n || ny<0 || nx>=n || nx<0) continue;
				flag=flag||(mp[ny][nx]=='1');
			}
			if (flag) vis[i][j]=true;
			cnt+=flag;
		}
	}
	if (c+cnt+e>n*n) cout << -1;
	else {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (!vis[i][j] && mp[i][j]=='0') {
					function<void(int, int)> dfs=[&](int y, int x) {
						if (e==0) return;
						mp[y][x]='2';
						vis[y][x]=true;
						e--;
						for (int d=0; d<4; d++) {
							int ny=y+dy[d];
							int nx=x+dx[d];
							if (ny>=n || ny<0 || nx>=n || nx<0) continue;
							if (vis[ny][nx]) continue;
							dfs(ny, nx);
						}
					};
					dfs(i, j);
					if (e>0) {
						cout << -1;
					}
					else {
						cout << 1 << '\n';
						rep(i, n) {
							cout << mp[i] << '\n';
						}
					}
					return 0;
				}
			}
		}
	}

	return 0;
}
