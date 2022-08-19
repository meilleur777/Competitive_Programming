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
		ll cnt2=0, cnt5=0;
		ll now2=2, now5=5;
		while (now2<=n) {
			cnt2+=n/now2;
			now2*=2;
		}
		while (now5<=n) {
			cnt5+=n/now5;
			now5*=5;
		}
		cout << min(cnt2, cnt5) << '\n';
	}

	return 0;
}
