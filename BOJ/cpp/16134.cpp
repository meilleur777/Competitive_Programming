#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n, r;
	cin >> n >> r;
	ll mod=1e9+7;
	vector<ll> fac(n+1);
	fac[0]=1;
	function<ll(ll, ll)> power=[&](ll a, ll b) {
		if (b==1) return a;
		ll tmp=power(a, b/2);
		tmp=tmp*tmp%mod;
		if (b%2) return tmp*a%mod;
		return tmp;
	};
	auto modinv=[&](ll a) { return power(a, mod-2); };
	for (int i=1; i<=n; i++) fac[i]=(fac[i-1]*i)%mod;
	cout << fac[n]*modinv(fac[r])%mod*modinv(fac[n-r])%mod;

	return 0;
}
