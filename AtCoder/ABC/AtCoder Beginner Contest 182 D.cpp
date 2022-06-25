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
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> mov(n), bes(n);
	mov[0]=a[0];
	bes[0]=a[0];
	for (int i=1; i<n; i++) {
		mov[i]=mov[i-1]+a[i];
		bes[i]=max(bes[i-1], mov[i-1]+a[i]);
	}
	ll now=0;
	ll ans=0;
	for (int i=0; i<n; i++) {
		ans=max(ans, now+bes[i]);
		now+=mov[i];
	}
	cout << ans;

	return 0;
}
