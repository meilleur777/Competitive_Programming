#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	
	int r, c;
	cin >> r >> c;
	vector<string> s(r);
	rep(i, r) cin >> s[i];

	queue<intp> q;
	vector<vector<int>> fire(r, vector<int>(c, -1));
	rep(i, r) rep(j, c) {
		if (s[i][j]=='F') {
			fire[i][j]=0;
			q.push({i, j});
		}
	}
	while (!q.empty()) {
		int y=q.front().first;
		int x=q.front().second;
		q.pop();

		rep(d, 4) {
			int ny=y+dy[d];
			int nx=x+dx[d];
			if (ny>=r || ny<0 || nx>=c || nx<0) continue;
			if (fire[ny][nx]!=-1) continue;
			if (s[ny][nx]=='#') continue;
			fire[ny][nx]=fire[y][x]+1;
			q.push({ny, nx});
		}
	}

	queue<pair<int, intp>> qq;
	vector<vector<bool>> vis(r, vector<bool>(c, false));
	rep(i, r) rep(j, c) {	
		if (s[i][j]=='J') {
			vis[i][j]=true;
			qq.push({0, {i, j}});
		}
	}
	while (!qq.empty()) {
		int now=qq.front().first;
		int y=qq.front().second.first;
		int x=qq.front().second.second;
		qq.pop();

		rep(d, 4) {
			int ny=y+dy[d];
			int nx=x+dx[d];
			if (ny>=r || ny<0 || nx>=c || nx<0) {
				cout << now+1;
				return 0;
			}
			if (s[ny][nx]=='#') continue;
			if (vis[ny][nx]) continue;
			if (fire[ny][nx]!=-1 && fire[ny][nx]<=now+1) continue;
			vis[ny][nx]=true;
			qq.push({now+1, {ny, nx}});
		}	
	}
	cout << "IMPOSSIBLE";

	return 0;
}
