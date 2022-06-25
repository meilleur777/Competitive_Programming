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

int h, w;
vector<int> siz;
vector<string> brd;
vector<vector<bool> > vis;

int dy[4]={0, 0, -1, 1};
int dx[4]={1, -1, 0, 0};

int DFS(int y, int x) {
	vis[y][x]=true;
	int ret=1;
	for (int i=0; i<4; i++) {
		int ny=y+dy[i], nx=x+dx[i];
		if (ny>=h || ny<0 || nx>=w || nx<0) continue;
		if (!vis[ny][nx] && brd[ny][nx]=='#') {
			ret+=DFS(ny, nx);
		}
	}
	return ret;
}

int main() {
	init_code();

	cin >> h >> w;
	brd.resize(h);
	rep(i, h) cin >> brd[i];
	vis=vector<vector<bool> >(h, vector<bool>(w, false));
	rep(i, h) rep(j, w) {
		if (!vis[i][j] && brd[i][j]=='#') {
			int tmp=DFS(i, j);
			siz.push_back(tmp);
		}
	}
	for (auto i:siz) {
		if (i<2) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";

	return 0;
}
