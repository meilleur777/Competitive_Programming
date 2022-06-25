#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<intp> a(n);
		rep(i, n) cin >> a[i].first >> a[i].second;
		map<int, ll> fcnt, scnt;
		rep(i, n) {
			fcnt[a[i].first]++;
			scnt[a[i].second]++;
		}
		ll ans=n*(n-1)*(n-2)/6;
		rep(i, n) {
			ans-=(fcnt[a[i].first]-1)*(scnt[a[i].second]-1);
		}
		cout << ans << '\n';
	}

	return 0;
}
