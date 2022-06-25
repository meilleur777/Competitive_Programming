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

ll power(ll a, ll b) {
	if (b == 1) return a;
	ll temp = power(a, b/2);
	temp = temp*temp%mod;
	if (b%2) return temp*a%mod;
	else return temp;
}

ll modInv(ll a, ll b) {
	return power(a, b-2);
}

int main() {
	init_code();

	ll N, K;
	cin >> N >> K;
	vector<ll> fac(N+1);
	fac[0] = 1;
	for (ll i = 1; i <= N; i++) {
		fac[i] = fac[i-1]*i%mod;
	}
	ll res = fac[N]*modInv(fac[K], mod)%mod*modInv(fac[N-K], mod)%mod;
	cout << res;			

	return 0;
}
