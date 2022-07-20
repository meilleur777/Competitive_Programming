#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int mx=-1;
		ll ans=0;
		for (int i=n-1; i>=0; i--) {
			mx=max(mx, a[i]);
			if (mx>a[i]) ans+=mx-a[i];
		}
		cout << ans << '\n';
	}

	return 0;
}
