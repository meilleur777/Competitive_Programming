#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

// n>2
// ncr(n-2, 0)+ncr(n-2, 1)+ncr(n-2, 2)+...+ncr(n-2, n-2)=pow(2, n-2)

ll mod=1e9+7;
ll power(ll a, ll b) {
	a%=mod;
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n==1) cout << 1 << '\n';
		else cout << power(2, n-2) << '\n';
	}

	return 0;
}
