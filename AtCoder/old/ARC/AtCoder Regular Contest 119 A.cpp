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
const ll INF=0x3F3F3F3F3F3F3F3F;

int main() {
	init_code();

	ll n;
	cin >> n;
	int b=__lg(n);
	ll ans=INF;
	for (int i=0; i<=b; i++) {
		ll a=n/(ll)pow(2, i);
		ll c=n%(ll)pow(2, i);
		ans=min(ans, a+i+c);
	}
	cout << ans;

	return 0;
}
