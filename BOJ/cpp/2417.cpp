#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	ll n;
	cin >> n;
	if (n==0) {
		cout << 0;
		return 0;
	}
	ll lo=0, hi=(1LL<<32)-1;
	ll ans=0;
	while (lo<=hi) {
		ll mid=(lo+hi)/2;
		ll tmp=mid*mid;
		if (tmp>=n) {
			hi=mid-1;
			ans=mid;
		}
		else lo=mid+1;
	}
	cout << ans;

	return 0;
}
