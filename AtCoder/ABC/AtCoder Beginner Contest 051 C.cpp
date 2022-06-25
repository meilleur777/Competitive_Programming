#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
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

int main() {
	init_code();

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	cout << string(tx-sx, 'R')+string(ty-sy, 'U')+string(tx-sx, 'L')
	+string(ty-sy, 'D')+'D'+string(tx-sx+1, 'R')+string(ty-sy+1, 'U')+
	"LU"+string(tx-sx+1, 'L')+string(ty-sy+1, 'D')+'R';

	return 0;
}
