#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int q;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		if (b%a) cout << 0;
		else {
			b/=a;
			if (b<2) cout << 0;
			else cout << 1;
		}
		cout << '\n';
	}

	return 0;
}
