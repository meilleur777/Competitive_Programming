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
vector<string> brd;
vector<vector<vector<int> > > dp;

int solve(int y, int x, bool last) {
	if (y==h-1 && x==w-1) {
		if (brd[y][x]=='#') {
			if (last==true) return 0;
			return 1;
		}
		return 0;
	}
	int& ret=dp[y][x][last];
	if (ret!=-1) return ret;
	ret=INF;
	if (y!=h-1) {
		if (brd[y+1][x]=='#') {
			if (last) ret=min(ret, solve(y+1, x, true));
			else ret=min(ret, solve(y+1, x, true)+1);
		}
		else ret=min(ret, solve(y+1, x, false));
	}
	if (x!=w-1) {
		if (brd[y][x+1]=='#') {
			if (last) ret=min(ret, solve(y, x+1, true));
			else ret=min(ret, solve(y, x+1, true)+1);
		}
		else ret=min(ret, solve(y, x+1, false));
	}
	return ret;
}

int main() {
	init_code();

	cin >> h >> w;
	brd.resize(h);
	dp=vector<vector<vector<int> > >(h, vector<vector<int> >(w, vector<int>(2, -1)));
	rep(i, h) cin >> brd[i];
	if (brd[0][0]=='#') cout << solve(0, 0, 1)+1;
	else cout << solve(0, 0, 0);

	return 0;
}
