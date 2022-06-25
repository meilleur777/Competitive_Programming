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

ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

int main() {
	init_code();

	ll x, y;
	cin >> x >> y;
	ll AB = x*y;
	ll start = (ll)sqrt((ld)AB);
	for (ll i = start; i >= 1; i--) {
		if (AB%i == 0 && gcd(i, AB/i) == x) {
			cout << i << ' ' << AB/i;
			break;
		}
	}	

	return 0;
}
