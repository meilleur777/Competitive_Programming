#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n%2) {
			cout << n*(n-1)*(n-2);
		}
		else {
			if (n%3) cout << n*(n-1)*(n-3);
			else cout << (n-1)*(n-2)*(n-3);
		}
		cout << '\n';
	}

	return 0;
}
