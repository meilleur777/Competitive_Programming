#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> llp;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<llp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());
	function<ll(llp, llp, llp)> ccw=[&](llp p, llp q, llp w) {
		return p.first*q.second+q.first*w.second+w.first*p.second
				-p.first*w.second-q.first*p.second-w.first*q.second;
	};
	sort(a.begin()+1, a.end(), [&](llp& p, llp& q) {
		ll t=ccw(a[0], p, q);
		if (t==0) return p<q;
		return t>0;
	});

	stack<llp> sk;
	sk.push(a[0]);
	sk.push(a[1]);
	for (int i=2; i<n; i++) {
		while (sk.size()>1) {
			auto p=sk.top();
			sk.pop();
			auto q=sk.top();
			if (ccw(q, p, a[i])>0) {
				sk.push(p);
				break;
			}
		}
		sk.push(a[i]);
	}

	cout << sk.size();

	return 0;
}
