#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> cnt(32, 0);
	rep(i, n) {
		int a;
		cin >> a;
		rep(j, 31) {
			cnt[j]+=!!(a&(1<<j));
		}
	}
	ll ans=1;
	ll mod=1e9+7;
	rep(i, n) {
		ll a=0;
		rep(j, 31) {
			if (cnt[j]>0) {
				cnt[j]--;
				a+=(1<<j);
			}
		}
		ans=(ans*a)%mod;
	}
	cout << ans;

	return 0;
}
