#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> intp;

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
vector<string> s;
vector<vector<bool>> vis;

int dy[]={0, 0, -1, 1};
int dx[]={1, -1, 0, 0};

int col(int y, int x) {
	if (s[y][x]=='#') return 1;
	return 0;;
}

intp dfs(int y, int x) {
	vis[y][x]=true;
	intp ret={col(y, x), 1};
	for (int d=0; d<4; d++) {
		int ny=y+dy[d], nx=x+dx[d];
		if (ny>=h || ny<0 || nx>=w || nx<0) continue;
		if (!vis[ny][nx] && col(y, x)!=col(ny, nx)) {
			intp tmp=dfs(ny, nx);
			ret.first+=tmp.first;
			ret.second+=tmp.second;
		}
	}
	return ret;
}

int main() {
	init_code();

	cin >> h >> w;
	s.resize(h);
	rep(i, h) cin >> s[i];
	vis=vector<vector<bool>>(h, vector<bool>(w, false));
	ll ans=0;	
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if (!vis[i][j]) {
				intp tmp=dfs(i, j);
				// cout << tmp.first << ' ' << tmp.second << '\n';
				ans+=tmp.first*(tmp.second-tmp.first);
			}
		}
	}
	cout << ans;

	return 0;
}
