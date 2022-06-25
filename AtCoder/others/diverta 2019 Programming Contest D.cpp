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

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp;//%mod;
	if (b%2) return tmp*a;//%mod;
	return tmp;
}

int main() {
	init_code();

	ll n;
	cin >> n;
	set<ll> res;
	for (ll p=1; p*p+p<n; p++) {
		if (n%p==0) {
			res.insert(n/p-1);
		}
	}
	ll ans=0;
	for (auto i:res) {
		ans+=i;
	}
	cout << ans;

	return 0;
}
