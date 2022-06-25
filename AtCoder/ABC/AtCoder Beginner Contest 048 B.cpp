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

ll f(ll n, ll x) {
	if (n==-1) return 0;
	return n/x+1;
}

int main() {
	init_code();

	ll a, b, x;
	cin >> a >> b >> x;
	cout << f(b, x)-f(a-1, x);

	return 0;
}
