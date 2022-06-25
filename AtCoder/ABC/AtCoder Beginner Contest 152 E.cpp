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

const ll mod=1e9+7;
const int INF=0x3F3F3F3F;

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}

int main() {
	init_code();

	int n;
	cin >> n;	
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> mp;
	rep(i, n) {
		int tmp=a[i];
		for (int j=2; j*j<=a[i]; j++) {
			if (tmp%j==0) {
				int cnt=0;
				while (tmp%j==0) {
					tmp/=j;
					cnt++;
				}
				mp[j]=max(mp[j], cnt);
			}
		}
		if (tmp!=1) {
			mp[tmp]=max(mp[tmp], 1);
		}
	}
	ll lcm=1;
	for (auto [a, b]:mp) {
		lcm*=power(a, b);
		lcm%=mod;
	}
	ll ans=0;
	for (auto i:a) {
		ans+=lcm*power(i, mod-2)%mod;
		ans%=mod;
	}
	cout << ans;

	return 0;
}
