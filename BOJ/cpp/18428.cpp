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

const int dy[]={0, 0, -1, 1};
const int dx[]={1, -1, 0, 0};

int n;
vector<intp> stu;
vector<string> brd;

bool chk() {
	for (auto i:stu) {
		for (int d=0; d<4; d++) {
			int y=i.first, x=i.second;
			while (true) {
				y+=dy[d], x+=dx[d];
				if (y>=n || y<0 || x>=n || x<0) break;
				if (brd[y][x]=='O') break;
				if (brd[y][x]=='T') return false;
			}
		}
	}
	return true;
}

void sol(int y, int x, int cnt) {
	if (y==n-1 && x==n) {
		if (cnt==3 && chk()) {
			cout << "YES";
			exit(0);
		}
		return;
	}
	if (x==n) {
		sol(y+1, 0, cnt);
		return;
	}
	if (brd[y][x]!='X') {
		sol(y, x+1, cnt);
		return;
	}
	if (cnt<3) {
		brd[y][x]='O';
		sol(y, x+1, cnt+1);
		brd[y][x]='X';
	}
	sol(y, x+1, cnt);
}

int main() {
	init_code();

	cin >> n;
	brd=vector<string>(n, string(n, '0'));
	rep(i, n) rep(j, n) {
		cin >> brd[i][j];
		if (brd[i][j]=='S') {
			stu.push_back({i, j});
		}
	}
	sol(0, 0, 0);
	cout << "NO";

	return 0;
}
