#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

ll gcd(ll a, ll b) {
	if (a%b==0) return b;
	return gcd(b, a%b);
}

ll eea(ll a, ll b, ll& x, ll& y) {
	if (b) {
		ll xx, yy;
		ll tmp=eea(b, a%b, xx, yy);
		x=yy;
		y=xx-yy*(a/b);
		return tmp;
	}
	else {
		x=1, y=0;
		return a;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n, a, x, y;
	cin >> n >> a;
	cout << (a+n-1)/n*n-a << ' ';
	if (gcd(n, a)!=1) cout << -1;
	else {
		eea(a, n, x, y);
		cout << (x+n)%n;
	}

	return 0;
}
