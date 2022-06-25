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

bool chk() {
	for (auto i:brd) {
		if (i!=string(w, '.')) return false;
	}
	return true;
}

void sol(int y, int x) {
	// cout << y << ' ' << x << '\n';
	if (y==h-1 && x==w-1) {
		if (chk()) {
			cout << "Possible";
			exit(0);
		}
		return;
	}
	if (x==w) {
		sol(y+1, 0);
		return;
	}
	if (x+1<w && brd[y][x+1]=='#') {
		brd[y][x+1]='.';
		sol(y, x+1);
		brd[y][x+1]='#';
	}
	if (y+1<h && brd[y+1][x]=='#') {
		brd[y+1][x]='.';
		sol(y+1, x);
		brd[y+1][x]='#';
	}
}

int main() {
	init_code();

	cin >> h >> w;
	brd.resize(h);
	rep(i, h) cin >> brd[i];
	brd[0][0]='.';
	sol(0, 0);
	cout << "Impossible";

	return 0;
}
