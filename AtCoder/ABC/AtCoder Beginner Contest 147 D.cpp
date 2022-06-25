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
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans=0;
	for (int i=0; i<60; i++) {
		int cnt=0;
		ll res=0;
		for (int j=0; j<n; j++) {
			if ((1LL<<i)&a[j]) {
				cnt++;
			}
		}
		for (int j=0; j<n; j++) {
			if ((1LL<<i)&a[j]) {
				cnt--;
				res+=n-j-1-cnt;
			}
			else {
				res+=cnt;
			}
		}
		ans+=power(2, i)*(res%mod)%mod;
		ans%=mod;
	}
	cout << (ans+mod)%mod;

	return 0;
}
