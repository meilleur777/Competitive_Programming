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
vector<string> a;
vector<vector<int>> dp;

int sol(int y, int x) {
	if (y==h-1 && x==w-1) {
		return 0;
	}
	int& ret=dp[y][x];
	if (ret!=-INF) return ret;
	int tmp;
	if (y+1!=h) {
		if (a[y+1][x]=='+') tmp=1;
		else tmp=-1;
		ret=max(ret, tmp-sol(y+1, x));
	}
	if (x+1!=w) {
		if (a[y][x+1]=='+') tmp=1;
		else tmp=-1;
		ret=max(ret, tmp-sol(y, x+1));
	}
	return ret;
}

int main() {
	init_code();

	cin >> h >> w;
	a.resize(h);
	rep(i, h) cin >> a[i];
	dp=vector<vector<int>>(h, vector<int>(w, -INF));
	if (sol(0, 0)>0) cout << "Takahashi";
	else if (sol(0, 0)==0) cout << "Draw";
	else cout << "Aoki";

	return 0;
}
