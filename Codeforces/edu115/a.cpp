#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int dy[]={0, 0, -1, -1, -1, 1, 1, 1};
int dx[]={1, -1, 0, 1, -1, 0, 1, -1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> a(2);
		rep(i, 2) cin >> a[i];
		queue<intp> q;
		q.push({0, 0});
		vector<vector<bool>> vis(2, vector<bool>(n, false));
		vis[0][0]=true;
		while (!q.empty()) {
			int y=q.front().first, x=q.front().second;
			q.pop();
			for (int d=0; d<8; d++) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=2 || ny<0 || nx>=n || nx<0) continue;
				if (!vis[ny][nx] && a[ny][nx]=='0')  {
					vis[ny][nx]=true;
					q.push({ny, nx});
				}
			}
		}
		if (vis[1][n-1]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
