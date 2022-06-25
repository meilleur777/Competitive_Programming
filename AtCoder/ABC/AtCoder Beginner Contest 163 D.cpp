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

	ll n, k;
	cin >> n >> k;
	ll lo=0, hi=0;
	ll now=0;
	ll ans=0;
	while (true) {
		lo+=now, hi+=n-now;
		if (lo>hi) break;
		if (now>=k-1) {
			ans+=hi-lo+1;
			ans%=mod;
		}
		now++;
	}
	cout << ans;

	return 0;
}
