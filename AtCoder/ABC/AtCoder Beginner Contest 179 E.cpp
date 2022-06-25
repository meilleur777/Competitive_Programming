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

	ll n, x, m;
	cin >> n >> x >> m;
	vector<ll> chk(m, -1);
	vector<ll> a;
	ll tmp=x;
	ll len=0;
	while (chk[tmp]==-1) {
		chk[tmp]=len;
		a.push_back(tmp);
		tmp=tmp*tmp%m;
		len++;
	}
	if (len>=n) {
		ll ans=0;
		for (ll i=0; i<n; i++) {
			ans+=a[i];
		}
		cout << ans;
	}
	else {
		ll cyc=len-chk[tmp];
		ll cycs=0;
		for (ll i=chk[tmp]; i<len; i++) {
			cycs+=a[i];
		}
		ll pre=0;
		for (ll i=0; i<chk[tmp]; i++) {
			pre+=a[i];
		}
		n-=chk[tmp];
		ll ans=pre;
		ans+=n/cyc*cycs;
		n%=cyc;
		for (ll i=chk[tmp]; i<chk[tmp]+n; i++) {
			ans+=a[i];
		}
		cout << ans;
	}

	return 0;
}
