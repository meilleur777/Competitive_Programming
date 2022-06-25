#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	for (int i=1; i<=t; i++) {
		ll p, q;
		cin >> p >> q;
		ll a=1, b=1;
		a%=q, b%=q;
		rep(i, p-1) {
			ll nxt=a+b;
			nxt%=q;
			a=b;
			b=nxt;
		}
		cout << "Case #" << i << ": " << a%q << '\n';
	}

	return 0;
}
