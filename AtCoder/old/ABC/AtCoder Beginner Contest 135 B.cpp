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

	int n;
	cin >> n;
	vector<int> a(n+1), b(n);
	rep(i, n+1) cin >> a[i];
	rep(i, n) cin >> b[i];
	ll ans=0;	
	for (int i=0; i<n; i++) {
		ll tmp=min(a[i], b[i]);
		b[i]-=tmp;
		a[i]-=tmp;
		ans+=tmp;
		tmp=min(a[i+1], b[i]);
		a[i+1]-=tmp;
		ans+=tmp;
	}
	cout << ans;

	return 0;
}
