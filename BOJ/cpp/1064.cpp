#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cout.precision(10);
	cout << fixed;
	
	vector<intp> a(3);
	rep(i, 3) cin >> a[i].first >> a[i].second;

	if ((a[1].second-a[0].second)*(a[2].first-a[0].first)==(a[2].second-a[0].second)*(a[1].first-a[0].first)) {
		cout << -1;
		return 0;
	}

	function<ld(ld)> sqr=[](ld a) {
		return a*a;
	};
	function<ld(int, int)> dis=[&](int p, int q) {
		return sqrt(sqr(a[p].first-a[q].first)+sqr(a[p].second-a[q].second));
	};

	vector<ld> res;
	rep(i, 3) {
		res.push_back(2.0*(dis(i, (i+1)%3)+dis((i+1)%3, (i+2)%3)));
	}
	sort(res.begin(), res.end());
	cout << res.back()-res.front();

	return 0;
}
