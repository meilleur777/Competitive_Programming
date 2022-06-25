#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	ll x, y;
	cin >> x >> y;
	ll z=y*100/x;
	if (z>=99) {
		cout << -1;
		return 0;
	}
	ll left=0, right=x;
	ll ans;
	while (left<=right) {
		ll mid=(left+right)/2;
		if ((y+mid)*100/(x+mid)>z) {
			ans=mid;
			right=mid-1;
		}
		else left=mid+1;
	}
	cout << ans;

	return 0;
}
