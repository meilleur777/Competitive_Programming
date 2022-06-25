#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	ll ans=LLONG_MAX;
	for (ll i=0; i<=min(max(a, c), n); i++) {
		ans=min({ans, i*b+max(0LL, n-i*a+c-1)/c*d, i*d+max(0LL, n-i*c+a-1)/a*b});
	}
	cout << ans;

	return 0;
}
