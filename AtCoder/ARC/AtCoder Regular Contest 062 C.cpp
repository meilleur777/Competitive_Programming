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

	ll n;
	cin >> n;
	ll t, a;
	cin >> t >> a;
	rep(i, n-1) {
		ll l, r;
		cin >> l >> r;
		if ((l>=t && r<a)) {
			ll c=(a+r-1)/r;
			l*=c, r*=c;
		}
		else if (l<t && r>=a) {
			ll c=(t+l-1)/l;
			l*=c, r*=c;
		}
		else if (l<t && r<a) {
			ll c1=(t+l-1)/l;
			ll c2=(a+r-1)/r;
			ll c=max(c1, c2);
			l*=c, r*=c;
		}
		t=l, a=r;
	}
	cout << t+a;

	return 0;
}
