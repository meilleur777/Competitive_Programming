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

int r, c;
vector<vector<int> > brd;
vector<vector<vector<ll> > > dp;

ll solve(int y, int x, int had) {
	if (y==r-1 && x==c-1) {
		if (brd[r-1][c-1]>0) {
			if (had<3) {
				return brd[r-1][c-1];
			}
		}
		return 0;
	}	
	ll& ret=dp[had][y][x];
	if (ret!=-1) return ret;
	if (brd[y][x]>0) {
		if (y+1!=r) {
			ret=max(ret, solve(y+1, x, had));
			if (had<3) {
				ret=max(ret, solve(y+1, x, 0)+brd[y][x]);
			}
		}
		if (x+1!=c) {
			ret=max(ret, solve(y, x+1, had));
			if (had<3) {	
				ret=max(ret, solve(y, x+1, had+1)+brd[y][x]);
			}
		}
	}
	else {
		if (y+1!=r) {
			ret=max(ret, solve(y+1, x, 0));
		}
		if (x+1!=c) {
			ret=max(ret, solve(y, x+1, had));
		}
	}
	return ret;
}

int main() {
	init_code();

	int k;
	cin >> r >> c >> k;
	brd=vector<vector<int> >(r, vector<int>(c, 0));
	dp=vector<vector<vector<ll> > >(4, vector<vector<ll> >(r, vector<ll>(c, -1)));
	rep(i, k) {
		int a, b, d;
		cin >> a >> b >> d;
		brd[a-1][b-1]=d;	
	}
	cout << solve(0, 0, 0);

	return 0;
}
