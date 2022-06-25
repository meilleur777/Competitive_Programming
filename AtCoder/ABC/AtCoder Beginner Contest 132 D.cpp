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

vector<ll> fac;
vector<ll> ivf;

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}

void cal() {
	fac.resize(2e3+2);
	ivf.resize(2e3+2);
	fac[0]=1;
	for (ll i=1; i<=2e3+1; i++) fac[i]=fac[i-1]*i%mod;
	for (ll i=0; i<=2e3+1; i++) ivf[i]=power(fac[i], mod-2)%mod;
}

ll ncr(ll n, ll r) {
	if (r>n) return 0;
	return fac[n]*ivf[r]%mod*ivf[n-r]%mod;
}

int main() {
	init_code();

	cal();
	int n, k;	
	cin >> n >> k;
	for (int i=1; i<=k; i++) {
		cout << ncr(n-k+1, i)*ncr(k-1, i-1)%mod << '\n';
	}

	return 0;
}
