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

	vector<ll> fac(21, 1);
	for (int i=1; i<21; i++) {
		fac[i]=fac[i-1]*i;
	}
	int n, t;
	cin >> n >> t;
	if (t==1) {
		ll k;
		cin >> k;
		vector<bool> chk(n+1, false);
		for (int i=0; i<n; i++) {
			for (int j=1; j<=n; j++) {
				if (chk[j]) continue;
				if (k>fac[n-i-1]) k-=fac[n-i-1];
				else {
					chk[j]=true;
					cout << j << ' ';
					break;
				}
			}
		}
	}
	else {
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		ll ans=0;
		vector<bool> chk(n+1, false);
		for (int i=0; i<n; i++) {
			for (int j=1; j<a[i]; j++) {
				if (!chk[j]) ans+=fac[n-i-1];
			}
			chk[a[i]]=true;
		}
		cout << ans+1;
	}

	return 0;
}
