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

int n;
vector<vector<int>> brd;
vector<vector<ll>> dp;

int dy[4]={0, 0, 1, -1};
int dx[4]={1, -1, 0, 0};

ll sol(int y, int x) {
	ll& ret=dp[y][x];
	if (ret!=-1) return ret;	
	ret=1;
	for (int d=0; d<4; d++) {
		int ny=y+dy[d], nx=x+dx[d];
		if (ny>=n || ny<0 || nx>=n || nx<0) continue;
		if (brd[ny][nx]>brd[y][x]) {
			ret=max(ret, sol(ny, nx)+1);
		}	
	}	
	return ret;
}

int main() {
	init_code();

	cin >> n;
	brd=vector<vector<int>>(n, vector<int>(n));
	dp=vector<vector<ll>>(n, vector<ll>(n, -1));
	rep(i, n) rep(j, n) cin >> brd[i][j];
	ll ans=1;
	rep(i, n) rep(j, n) ans=max(ans, sol(i, j));
	cout << ans;

	return 0;
}
