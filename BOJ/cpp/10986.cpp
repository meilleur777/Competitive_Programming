#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n, m, a, ans=0;
	cin >> n >> m;
	vector<ll> sum(n+1, 0), cnt(m, 0);
	rep(i, n) {
		cin >> a;
		sum[i+1]=(sum[i]+a)%m;
	}
	rep(i, n+1) cnt[sum[i]]++;
	rep(i, m) ans+=cnt[i]*(cnt[i]-1)/2;
	cout << ans;

	return 0;
}
