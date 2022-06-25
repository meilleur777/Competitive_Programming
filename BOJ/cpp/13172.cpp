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

const ll mod = 1e9+7;

ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

ll power(ll a, ll b) {
	if (b == 1) return a;
	ll temp = power(a, b/2);
	temp = temp*temp%mod;
	if (b%2) return temp*a%mod;		
	else return temp;
}

int main() {
	init_code();

	ll M;
	cin >> M;
	ll ans = 0;
	while (M--) {
		ll n, s;
		cin >> n >> s;
		ll g = gcd(n, s);
		n /= g, s /= g;
		ans += s*power(n, mod-2)%mod;
		ans %= mod;
	}
	cout << ans;

	return 0;
}
