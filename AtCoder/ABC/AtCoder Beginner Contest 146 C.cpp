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

	ll a, b, x;
	cin >> a >> b >> x;
	ll left=0, right=1e9;
	ll ans=0;
	while (left<=right) {
		ll mid=(left+right)/2;
		string tmp=to_string(mid);
		ll d=tmp.size();
		if (x>=a*mid+b*d) {
			ans=mid;
			left=mid+1;
		}
		else right=mid-1;
	}
	cout << ans;

	return 0;
}
