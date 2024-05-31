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

	int a, b;
	cin >> a >> b;
	a--, b--;
	vector<string> brd(100, string(100, '#'));
	for (int i=50; i<100; i++) brd[i]=string(100, '.');
	int now=100;
	while (a--) {
		int tmp=now;
		brd[now/100][now%100]='.';
		now+=2;
		if (tmp/100 != now/100) now+=100;
	}
	now=5100;
	while (b--) {
		int tmp=now;
		brd[now/100][now%100]='#';
		now+=2;
		if (tmp/100 != now/100) now+=100;
	}
	cout << 100 << ' ' << 100 << '\n';
	rep(i, 100) cout << brd[i] << '\n';

	return 0;
}
