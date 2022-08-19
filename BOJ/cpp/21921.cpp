#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll now=0;
	rep(i, x) now+=a[i];
	ll ans=now;
	ll cnt=1;
	for (int i=x; i<n; i++) {
		now+=a[i];
		now-=a[i-x];
		if (now>ans) {
			cnt=1;
			ans=now;
		}
		else if (now==ans) cnt++;
	}
	if (ans==0) cout << "SAD";
	else cout << ans << '\n' << cnt;


	return 0;
}
