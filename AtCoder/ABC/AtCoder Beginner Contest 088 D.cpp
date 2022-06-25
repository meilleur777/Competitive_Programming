#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

const int dy[4]={0, 0, -1, 1};
const int dx[4]={1, -1, 0, 0};

int main() {
	init_code();

	int h, w;
	cin >> h >> w;
	vector<string> brd(h);
	rep(i, h) cin >> brd[i];
	queue<intp> q;
	vector<vector<int> > vis(h, vector<int>(w, -1));
	int cnt=0;
	rep(i, h) rep(j, w) {
		if (brd[i][j]=='#') cnt++;
	}
	vis[0][0]=0;
	q.push({0, 0});
	while (!q.empty()) {
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		if (y==h-1 && x==w-1) {
			break;
		}
		for (int i=0; i<4; i++) {
			int ny=y+dy[i], nx=x+dx[i];
			if (ny>=h || ny<0 || nx>=w || nx<0) continue;
			if (vis[ny][nx]==-1 && brd[ny][nx]=='.') {
				vis[ny][nx]=vis[y][x]+1;
				q.push({ny, nx});
			}
		}
	}
	if (vis[h-1][w-1]==-1) {
		cout << -1;
	}
	else {
		cout << h*w-(vis[h-1][w-1]+1)-cnt;	
	}

	return 0;
}
