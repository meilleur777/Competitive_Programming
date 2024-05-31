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

int main() {
	init_code();

	ll a, b;
	cin >> a >> b;
	ll g=gcd(a, b);
	ll t=g;
	set<int> m;
	for (ll i=2; i*i<=t; i++) {
		while (g%i==0) {
			g/=i;
			m.insert(i);
		}
	}
	if (g!=1) m.insert(g);
	cout << m.size()+1;

	return 0;
}
