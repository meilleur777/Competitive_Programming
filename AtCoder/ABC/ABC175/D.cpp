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

	int n, k;
	cin >> n >> k;
	vector<ll> p(n), c(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, n) cin >> c[i];
	ll ans=-1e18;
	for (int i=0; i<n; i++) {
		int sta=i;
		int now=sta;
		vector<ll> a;
		ll cys=0;
		while (true) {
			now=p[now];
			cys+=c[now];
			a.push_back(c[now]);
			if (now==sta) break;
		}
		ll tsu=0;
		for (int j=0; j<a.size(); j++) {
			if (j+1>k) break;
			tsu+=a[j];
			ans=max(ans, tsu);
			if (cys>0) {
				ans=max(ans, (k-1-j)/((int)a.size())*cys+tsu);
			}
		}	
	}
	cout << ans;

	return 0;
}
