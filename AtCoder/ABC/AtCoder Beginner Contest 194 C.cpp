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
	vector<ll> a(n+1);
	rep(i, n) cin >> a[i+1];
	vector<ll> psm(n+1, 0), sqm(n+1, 0);
	for (int i=1; i<=n; i++) {
		psm[i]=psm[i-1]+a[i];
		sqm[i]=sqm[i-1]+a[i]*a[i];
	}
	ll ans=0;
	for (int i=2; i<=n; i++) {
		ans+=(i-1)*a[i]*a[i]-2*a[i]*psm[i-1]+sqm[i-1];
	}
	cout << ans;

	return 0;
}
