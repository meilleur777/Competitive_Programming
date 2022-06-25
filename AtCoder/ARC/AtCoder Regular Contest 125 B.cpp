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

const ll mod=998244353;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	ll N;
	cin >> N;
	ll ans=0;
	for (ll i=1; i*i<=N; i++) {
		ll tmp=min(N/i, 2*N-i);
		tmp=tmp-i+1;
		ans+=(tmp+1)/2;
		ans%=mod;
	}
	cout << ans;

	return 0;
}
