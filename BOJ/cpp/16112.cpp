#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll ans=0;
	sort(a.begin(), a.end());
	for (int i=0; i<n; i++) {
		ans+=min(i, k)*(a[i]);
	}
	cout << ans;

	return 0;
}
