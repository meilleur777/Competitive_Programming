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

int dy[]={0, 0, -1, 1};
int dx[]={1, -1, 0, 0};

int main() {
	init_code();

	int h, w;
	cin >> h >> w;
	vector<string> brd(h);
	rep(i, h) cin >> brd[i];
	queue<intp> q;
	vector<vector<int>> vis(h, vector<int>(w, -1));
	intp edp;
	vector<vector<intp>> alp(26);
	rep(i, h) rep(j, w) {
		if (brd[i][j]=='S')	{
			vis[i][j]=0;
			q.push({i, j});
		}
		else if (brd[i][j]=='G') {
			edp=make_pair(i, j);
		}
		else if (isalpha(brd[i][j])) {
			alp[brd[i][j]-'a'].push_back(make_pair(i, j));
		}
	}
	vector<bool> use(26, false);
	while (!q.empty()) {
		int y=q.front().first, x=q.front().second;
		q.pop();
		for (int d=0; d<4; d++) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=h || ny<0 || nx>=w || nx<0) continue;
			if (vis[ny][nx]!=-1) continue;
			if (brd[ny][nx]=='#') continue;
			vis[ny][nx]=vis[y][x]+1;
			q.push({ny, nx});
		}
		if (brd[y][x]!='G' && brd[y][x]!='S' && isalpha(brd[y][x])) {
			if (use[brd[y][x]-'a']) continue;
			use[brd[y][x]-'a']=true;
			for (auto i:alp[brd[y][x]-'a']) {
				if (vis[i.first][i.second]!=-1) continue;
				vis[i.first][i.second]=vis[y][x]+1;
				q.push(i);
			}
		}
	}
	if (vis[edp.first][edp.second]==-1) cout << -1;
	else cout << vis[edp.first][edp.second];

	return 0;
}
