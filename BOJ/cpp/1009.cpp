#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b;
		c=1;
		rep(i, b) {
			c=c*a%10;
		}
		if (c==0) c=10;
		cout << c << '\n';
	}

	return 0;
}
