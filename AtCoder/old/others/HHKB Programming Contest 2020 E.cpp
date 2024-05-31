#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const ll mod=1e9+7;

int H, W;
int ans=0;
int full;
vector<string> brd;
int dy[4]={0, 0, -1, 1};
int dx[4]={1, -1, 0, 0};
vector<int> pos;

ll cnt() {
	ll ret=0;
	for (auto i : brd) {
		for (auto j : i) {
			if (j=='O') {
				ret++;
			}
		}
	}
	return ret;
}

bool inRange(int y, int x) {
	return (y>=0 && y<H && x>=0 && x<W);
}

void solve(int y, int x) {
	ll temp=cnt();
	if (temp==full) {
		ans+=full*((ll)pow(2, pos[y*W+x])%mod);
		ans%=mod;
		return;
	}
	if (y==H) {
		ans+=temp;
		ans%=mod;
		return;
	}
	if (x==W) {
		solve(y+1, 0);
		return;
	}
	if (brd[y][x]=='#') {
		solve(y, x+1);
		return;
	}
	solve(y, x+1);
	vector<intp> memo;
	if (brd[y][x]=='.') {
		brd[y][x]='O';
		memo.push_back({y, x});
	}
	for (int i=0; i<4; i++) {
		int ny=y+dy[i], nx=x+dx[i];
		while (inRange(ny, nx) && brd[ny][nx]!='#') {
			if (brd[ny][nx]=='.') {
				brd[ny][nx]='O';
				memo.push_back({ny, nx});
			}
			ny+=dy[i], nx+=dx[i];
		}		
	}
	solve(y, x+1);
	for (auto i : memo) {
		brd[i.first][i.second]='.';
	}
}

int main() {
	init_code();

	cin >> H >> W;
	full=H*W;
	brd.resize(H);
	rep(i, H) {
		cin >> brd[i];
		for (auto j : brd[i]) {
			if (j=='#') {
				full--;
			}
		}
	}
	pos=vector<int>(H*W+1, 0);
	if (brd[H-1][W-1]=='.') {
		pos[H*W-1]=1;
	}
	for (int i=H*W-2; i>=0; i--) {
		pos[i]+=pos[i+1];
		if (brd[i/W][i%W]=='.') {
			pos[i]++;
		}
	
}	solve(0, 0);
	cout << ans;

	return 0;
}
