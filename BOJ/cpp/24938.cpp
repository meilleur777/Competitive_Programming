#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll sum=0;
	rep(i, n) sum+=a[i];
	sum/=n;
	vector<pair<ll, ll>> b;
	rep(i, n) {
		if (a[i]>sum) {
			b.push_back({a[i]-sum, i});
		}
	}
	int ptr=0;
	ll ans=0;
	rep(i, n) {
		while (a[i]<sum) {
			if (b[ptr].first<sum-a[i]) {
				ans+=llabs(i-b[ptr].second)*b[ptr].first;
				a[i]+=b[ptr].first;
				ptr++;
			}
			else {
				ans+=llabs(i-b[ptr].second)*(sum-a[i]);
				b[ptr].first-=sum-a[i];
				a[i]=sum;
			}
		}
	}
	cout << ans;

	return 0;
}
