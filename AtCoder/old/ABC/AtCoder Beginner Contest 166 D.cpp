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

	ll x;
	cin >> x;
	for (ll b=-500; b<=500; b++) {
		for (ll a=-500; a<=500; a++) {
			if ((ll)pow(a, 5)==x+(ll)pow(b, 5)) {
				cout << a << ' ' << b << '\n';
				return 0;
			}
		}
	}	

	return 0;
}
