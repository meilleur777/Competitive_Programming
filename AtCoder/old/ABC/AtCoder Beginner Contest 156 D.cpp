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

const ll mod=1e9+7;
const int INF=0x3F3F3F3F;

ll power(ll a, ll b) {
	ll res=1;
	while (b) {
		if (b&1) {
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}

ll ncr(ll n, ll r) {
	ll res=1;
	for (ll i=1; i<=r; i++) {
		res*=(n-i+1);
		res%=mod;
		res*=power(i, mod-2);
		res%=mod;
	}
	return res;
}

int main() {
	init_code();

	int n, a, b;
	cin >> n >> a >> b;
	ll ans=(power(2, n)+mod-1)%mod;
	ans-=ncr(n, a);
	ans=(ans+mod)%mod;
	ans-=ncr(n, b);
	ans=(ans+mod)%mod;
	cout << ans;

	return 0;
}
