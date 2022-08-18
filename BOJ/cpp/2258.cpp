#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll n, m;
	cin >> n >> m;
	vector<intp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), [&](const intp& p, const intp& q) {
		if (p.second==q.second) return p.first>q.first;
		return p.second<q.second;
	});

	bool change=true;
	ll ans=1e15;
	ll now=0;
	ll cost=0;
	for (int i=0; i<n; i++) {
		if (change) {
			cost=0;
			change=false;
		}

		cost+=a[i].second;
		now+=a[i].first;
		if (now>=m) {
			ans=min(ans, cost);
		}

		if (i!=n-1) {
			if (a[i].second!=a[i+1].second) {
				change=true;
			}
		}
	}
	if (ans==(ll)1e15) cout << -1;
	else cout << ans;

	return 0;
}
