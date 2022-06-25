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

	int n;
	cin >> n;
	vector<intp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;
	rep(i, n) {
		int g=gcd(a[i].first, a[i].second);
		a[i].first/=g;
		a[i].second/=g;
	}
	ll l=a[0].second;
	rep(i, n-1) {
		l=lcm(l, a[i+1].second);
	}
	a[0].first*=l/a[0].second;
	ll ans=a[0].first;
	rep(i, n-1) {
		a[i+1].first*=l/a[i+1].second;
		ans=gcd(ans, a[i+1].first);
	}
	cout << ans << ' ' << l; 

	return 0;
}
