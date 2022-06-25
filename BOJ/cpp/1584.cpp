#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<vector<int>> a(501, vector<int>(501, 0));
	int n;
	cin >> n;
	rep(k, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i=min(x1, x2); i<=max(x1, x2); i++) {
			for (int j=min(y1, y2); j<=max(y1, y2); j++) {
				a[i][j]=1;
			}
		}
	}
	int m;
	cin >> m;
	rep(k, m) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i=min(x1, x2); i<=max(x1, x2); i++) {
			for (int j=min(y1, y2); j<=max(y1, y2); j++) {
				a[i][j]=2;
			}
		}
	}
	int inf=0x3f3f3f3f;
	vector<vector<int>> dis(501, vector<int>(501, inf));
	priority_queue<pair<int, intp>, vector<pair<int, intp>>, greater<pair<int, intp>>> pq;
	dis[0][0]=0;
	pq.push({dis[0][0], {0, 0}});
	int dy[]={0, 0, -1, 1};
	int dx[]={1, -1, 0, 0};
	while (!pq.empty()) {
		int y=pq.top().second.first;
		int x=pq.top().second.second;
		int now=pq.top().first;
		pq.pop();
		if (now>dis[y][x]) continue;
		rep(d, 4) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=501 || ny<0 || nx>=501 || nx<0) continue;
			if (a[ny][nx]!=2 && dis[ny][nx]>dis[y][x]+a[ny][nx]) {
				dis[ny][nx]=dis[y][x]+a[ny][nx];
				pq.push({dis[ny][nx], {ny, nx}});
			}
		}
	}
	if (dis[500][500]>=inf) cout << -1;
	else cout << dis[500][500];

	return 0;
}
