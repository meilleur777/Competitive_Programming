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

int main() {
	init_code();

	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	X--, Y--;
	vector<string> brd(H);
	rep(i, H) cin >> brd[i];
	int cnt=1;
	int tmp=Y+1;
	while (tmp<W && brd[X][tmp]=='.') {
		cnt++;
		tmp++;
	}
	tmp=Y-1;
	while (tmp>=0 && brd[X][tmp]=='.') {
		cnt++;
		tmp--;
	}
	tmp=X+1;
	while (tmp<H && brd[tmp][Y]=='.') {
		cnt++;
		tmp++;
	}
	tmp=X-1;
	while (tmp>=0 && brd[tmp][Y]=='.') {
		cnt++;
		tmp--;
	}
	cout << cnt;

	return 0;
}
