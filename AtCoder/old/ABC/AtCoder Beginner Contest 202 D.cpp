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



ll ncr(ll n, ll r) {	
	if (n<r) return 0;
	ll ans=1;
	for (int i=0; i<r; i++) {
		ans*=n-i;
		ans/=i+1;
	}
	return ans;
}

int main() {
	init_code();

	ll a, b, k;
	cin >> a >> b >> k;
	int all=a+b;
	rep(i, all) {
		ll tmp=ncr(all-i-1, a-1);
		if (a==0) {
			rep(i, b) cout << 'b';
			return 0;
		}
		else if (b==0) {
			rep(i, a) cout << 'a';
			return 0;
		}
		if (k>tmp) {
			b--;
			cout << 'b';
			k-=tmp;
		}
		else {
			a--;
			cout << 'a';
		}
	}

	return 0;
}
