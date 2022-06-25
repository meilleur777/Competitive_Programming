#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ans=0;
	int aa=n-1, bb=0;
	while (aa>=0 && bb<m && a[aa]>=b[bb]) {
		ans+=a[aa]-b[bb];
		aa--;
		bb++;
	}
	cout << ans;

	return 0;
}
