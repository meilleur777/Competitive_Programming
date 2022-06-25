#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n;
	cin >> n;
	vector<ll> fac(22);
	fac[0]=1;
	for (ll i=1; i<=21; i++) {
		fac[i]=fac[i-1]*i;
	}
	for (int i=1; i<(1<<21); i++) {
		ll res=0;
		for (int j=0; j<=21; j++) {
			if (i&(1<<j)) {
				res+=fac[j];
			}
		}
		if (res==n) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}
