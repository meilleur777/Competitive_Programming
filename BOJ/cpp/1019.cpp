#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int left=1;
	vector<ll> cnt(10, 0);
	int now=1;
	auto www=[&](int a) {
		string s=to_string(a);
		for (auto i:s) cnt[i-'0']+=now;
	};
	while (left<=n) {
		while (left%10!=0 && left<=n) {
			www(left);
			left++;
		}
		if (left>n) break;
		while (n%10!=9 && left<=n) {
			www(n);
			n--;
		}
		n/=10, left/=10;
		rep(i, 10) cnt[i]+=(n-left+1)*now;
		now*=10;
	}
	rep(i, 10) cout << cnt[i] << ' ';

	return 0;
}
