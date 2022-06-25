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

ll power(ll a, ll b) {
	ll res=1;
	for ( ; b; b>>=1) {
		if (b&1) {
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
	}
	return res;
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	vector<int> cnt(*max_element(d.begin(), d.end())+1, 0);
	rep(i, n) cnt[d[i]]++;
	if (cnt[0]!=1 || d[0]!=0) {
		cout << 0;
		return 0;
	}
	ll ans=1;
	int t=*max_element(d.begin(), d.end());
	for (int i=1; i<=t; i++) {
		if (cnt[i-1]==0) {
			cout << 0;
			return 0;
		}
		ans*=power(cnt[i-1], cnt[i]);
		ans%=mod;
	}
	cout << ans;

	return 0;
}
