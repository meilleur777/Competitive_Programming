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

const int NUM=2019;

int main() {
	init_code();

	ll L, R;
	cin >> L >> R;
	if (R-L>2019) {
		cout << 0;
		return 0;
	}
	ll res=INF;
	for (ll i=L; i<=R; i++) {
		for (ll j=i+1; j<=R; j++) {
			res=min(res, i*j%NUM);
		}	
	}
	cout << res;

	return 0;
}
