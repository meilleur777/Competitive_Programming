#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n;
	m=n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];

	deque<pair<intp, int>> dq;
	dq.push_front({{0, 0}, 0});
	vector<vector<int>> dis(n, vector<int>(m, 1e6));
	dis[0][0]=0;

	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});

	while (!dq.empty()) {
		int y=dq.front().first.first;
		int x=dq.front().first.second;
		int time=dq.front().second;
		dq.pop_front();

		rep(d, 4) {
			int ny=y+dy[d];
			int nx=x+dx[d];
			if (ny>=n || ny<0 || nx>=m || nx<0) continue;
			if (dis[ny][nx]>dis[y][x]+1-(a[ny][nx]-'0')) {
				dis[ny][nx]=dis[y][x]+1-(a[ny][nx]-'0');
				if (a[ny][nx]=='0') dq.push_back({{ny, nx}, dis[ny][nx]});
				else dq.push_front({{ny, nx}, dis[ny][nx]});
			}
		}
	}
	cout << dis[n-1][m-1];

	return 0;
}
