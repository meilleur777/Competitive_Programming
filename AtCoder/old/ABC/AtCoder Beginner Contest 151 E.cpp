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

vector<ll> fac(1e5+1, 0);
vector<ll> ivf(1e5+1, 0);

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}	

void calc() {
	fac[0]=1;
	for (int i=1; i<=1e5; i++) {
		fac[i]=fac[i-1]*i%mod;
	}
	for (int i=0; i<=1e5; i++) {
		ivf[i]=power(fac[i], mod-2);
	}
}

ll ncr(ll n, ll r) {
	if (r>n) return 0;	
	return fac[n]*ivf[r]%mod*ivf[n-r]%mod;
}

int main() {
	init_code();										

	calc();
	int n, k;
	cin >> n >> k;
	vector<int> a(n);		    		
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	ll ans=0;
	for (int i=n-1; i>=k-1; i--) {	
		ans+=a[i]*ncr(i, k-1);
		ans%=mod;
	}
	for (int i=0; i<n-k+1; i++) {		
		ans-=a[i]*ncr(n-i-1, k-1);
		ans%=mod;
	}
	cout << (ans+mod)%mod;

	return 0;
}
