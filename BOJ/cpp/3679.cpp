#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> llp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vector<pair<llp, int>> a(n);
		rep(i, n) {
			cin >> a[i].first.first >> a[i].first.second;
			a[i].second=i;
		}

		sort(a.begin(), a.end());
		function<ll(llp, llp, llp)> ccw=[&](llp p, llp q, llp w) {
			return p.first*q.second+q.first*w.second+w.first*p.second
					-p.first*w.second-q.first*p.second-w.first*q.second;
		};
		function<ll(ll)> sqr=[&](ll q) {
			return q*q;
		};
		function<ll(llp, llp)> dis=[&](llp p, llp q) {
			return sqr(p.first-q.first)+sqr(p.second-q.second);
		};
		sort(a.begin()+1, a.end(), [&](pair<llp, int>& p, pair<llp, int>& q) {
			ll t=ccw(a[0].first, p.first, q.first);
			if (t==0) return dis(a[0].first, p.first)<dis(a[0].first, q.first);
			return t>0;
		});

		int ptr=(int)a.size()-1;
		while (ccw(a[0].first, a[ptr].first, a[ptr-1].first)==0) ptr--;
		reverse(a.begin()+ptr, a.end());

		for (auto i:a) cout << i.second << ' ';
		cout << '\n';
	}

	return 0;
}
