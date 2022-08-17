#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

const ll mod=1e4+7;

vector<ll> fac(60);

ll power(ll a, ll b) {
	if (b==1) return a;
	ll t=power(a, b/2);
	t=t*t%mod;
	if (b%2) return t*a%mod;
	return t;
}

ll modInv(ll a, ll b) {
	return power(a, b-2);
}

ll cmb(ll a, ll b) {
	return fac[a]*modInv(fac[b], mod)%mod*modInv(fac[a-b], mod)%mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;

	fac[0]=1;
	for (ll i=1; i<=55; i++) {
		fac[i]=i*fac[i-1]%mod;
	}

	ll ans=0;
	for (ll i=1; i<=n/4; i++) {
		ll tmp=cmb(13, i)*cmb(52-4*i, n-i*4)%mod;

		if (i%2) ans+=tmp;
		else ans=(ans-tmp+mod);
		ans%=mod;
	}
	cout << ans;

	return 0;
}
