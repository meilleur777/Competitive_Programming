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

	ll a, b;
	cin >> a >> b;
	if (llabs(a-b)>1) {
		cout << 0;
		return 0;
	}
	vector<ll> fac(max(a, b)+1, 1);
	for (ll i=1; i<=max(a, b); i++) {
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
	}
	ll ans=fac[a]*fac[b]%mod;
	if (a==b) {
		ans*=2;
		ans%=mod;
	}
	cout << ans;

	return 0;
}
