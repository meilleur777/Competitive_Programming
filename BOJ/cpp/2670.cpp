#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cout << fixed;
	cout.precision(3);
	
	int n;
	cin >> n;
	vector<ld> a(n);
	rep(i, n) cin >> a[i];
	ld ans=a[0];
	for (int i=1; i<n; i++) {
		a[i]=max(a[i], a[i]*a[i-1]);
		ans=max(ans, a[i]);
	}
	cout << ans;

	return 0;
}
