#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*return 0 to x*/
ll cnt(ll x) {
	ll res = 0;
	
	while (x) {
		res += x;
		x /= 10;
	}
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int l, r;
		cin >> l >> r;
		
		ll cntl = cnt(l), cntr = cnt(r);	
		
		cout << cntr - cntl << '\n';	
	}	
}

