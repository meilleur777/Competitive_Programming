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

ll gcd(ll a, ll b) {
	if (a%b==0) return b;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a/gcd(a, b)*b;
}

int main() {
	init_code();

	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans=0;
	for (int i=1; i<(1<<n); i++) {
		int cnt=0;
		ll tmp=1;
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				tmp=lcm(tmp, a[j]);
				cnt++;
			}
		}
		ll forr=r/tmp;
		ll forl=(l-1)/tmp;
		tmp=forr-forl;
		if (cnt%2==0) tmp*=-1;
		ans+=tmp;
	}
	cout << ans;

	return 0;
}
