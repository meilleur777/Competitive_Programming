#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

int H, W;
vector<string> brd;
vector<vector<int> > cache;

int solve(int y, int x) {
	if (y==H-1 && x==W-1) return 1;
	int& ret=cache[y][x];
	if (ret!=-1) return ret;
	ret=0;
	if (y!=H-1 && brd[y+1][x]=='.') {
		ret+=solve(y+1, x);
		ret%=mod;
	}
	if (x!=W-1 && brd[y][x+1]=='.') {
		ret+=solve(y, x+1);
		ret%=mod;
	}
	return ret;
}

int main() {
	init_code();

	cin >> H >> W;
	brd.resize(H);
	cache=vector<vector<int> >(H, vector<int>(W, -1));	
	rep(i, H) cin >> brd[i];
	cout << solve(0, 0);

	return 0;
}
