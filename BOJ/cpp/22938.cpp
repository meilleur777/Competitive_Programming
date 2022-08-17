#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	function<ll(ll)> sqr=[&](ll k) {
		return k*k;
	};
	if (sqr(c+f)>sqr(a-d)+sqr(b-e)) cout << "YES";
	else cout << "NO";

	return 0;
}
