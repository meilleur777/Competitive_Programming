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

	ll n, y;
	cin >> n >> y;
	y/=1000;
	for (ll a=0; a<=2000; a++) {
		for (ll b=0; b<=2000; b++) {
			ll c=y-a*10-b*5;
			if (c<0) continue;
			if (a+b+c==n) {
				cout << a << ' ' << b << ' ' << c;
				return 0;
			}
		}
	}
	cout << "-1 -1 -1";

	return 0;
}
