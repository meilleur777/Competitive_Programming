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

	int n, k, s;
	cin >> n >> k >> s;
	if (s==1e9) {
		rep(i, k) cout << s << ' ';
		rep(i, n-k) cout << 1 << ' ';
	}
	else {
		rep(i, k) cout << s << ' ';
		rep(i, n-k) cout << s+1 << ' ';
	}

	return 0;
}
