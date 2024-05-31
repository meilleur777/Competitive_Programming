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

	ll q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	q*=4, h*=2;
	if (n%2) {
		cout << min({q, h, s})+min((n-1)*min({q, h, s}), n/2*d);
	}
	else {
		cout << min(n*min({q, h, s}), n/2*d);
	}

	return 0;
}
