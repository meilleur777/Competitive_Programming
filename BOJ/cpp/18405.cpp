#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	int s, X, Y;
	cin >> s >> X >> Y;

	queue<pair<intp, int>> q;
	for (int i=1; i<=1000; i++) {
		rep(j, n) rep(k, n) {
			if (a[j][k]==i) {
				q.push({{j, k}, 0});
			}
		}
	}

	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	while (!q.empty()) {
		int y=q.front().first.first;
		int x=q.front().first.second;
		int now=q.front().second;
		q.pop();
		if (now>=s) break;
		rep(d, 4) {
			int ny=y+dy[d];
			int nx=x+dx[d];
			if (ny>=n || ny<0 || nx>=n || nx<0) continue;
			if (a[ny][nx]) continue;
			a[ny][nx]=a[y][x];
			q.push({{ny, nx}, now+1});
		}
	}
	cout << a[X-1][Y-1];


	return 0;
}
