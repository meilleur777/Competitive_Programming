#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int INF=0x3F3F3F3F;

bool sol2(ll x, ll y, ll a, ll b) {
	rep(i, 2) {
		ll tmpa=(a+x-1)/x;
		ll tmpb=(b+x-1)/x;
		if (tmpa+tmpb<=y) return true;
		swap(x, y);
	}
	return false;
}

bool sol3(ll x, ll y, ll a, ll b, ll c) {
	rep(i, 2) {
		rep(j, 3) {
			ll tmp=(a+x-1)/x;
			if (tmp<y && sol2(y-tmp, x, b, c)) {
				return true;
			}
			swap(a, b);
			swap(b, c);
		}
		swap(x, y);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	if (sol3(x, y, a, b, c)) cout << "Yes";
	else cout << "No";

	return 0;
}
