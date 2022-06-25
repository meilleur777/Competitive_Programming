#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int dy[]={0, 0, -1, 1};
	int dx[]={1, -1, 0, 0};
	int cnt=1;
	while (true) {
		int n;
		cin >> n;
		if (!n) return 0;
		vector<vector<int>> a(n, vector<int>(n)), dis(n, vector<int>(n, INF));
		rep(i, n) rep(j, n) cin >> a[i][j];
		dis[0][0]=a[0][0];
		priority_queue<pair<intp, int>, vector<pair<intp, int>>, greater<pair<intp, int>>> pq;
		pq.push({{0, 0}, dis[0][0]});
		while (!pq.empty()) {
			int y=pq.top().first.first, x=pq.top().first.second;
			int cos=pq.top().second;
			pq.pop();
			if (dis[y][x]<cos) continue;
			rep(d, 4) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=n || ny<0 || nx>=n || nx<0) continue;
				if (dis[ny][nx]>dis[y][x]+a[ny][nx]) {
					dis[ny][nx]=dis[y][x]+a[ny][nx];
					pq.push({{ny, nx}, dis[ny][nx]});
				}
			}
		}
		cout << "Problem " << cnt << ": " << dis[n-1][n-1] << '\n';
		cnt++;
	}

	return 0;
}
