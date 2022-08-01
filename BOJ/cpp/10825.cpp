#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<pair<string, int>, intp>> a(n);
	rep(i, n) cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
	sort(a.begin(), a.end(), [&](pair<pair<string, int>, intp>& p, pair<pair<string, int>, intp>& q) {
		if (p.first.second!=q.first.second) return p.first.second>q.first.second;
		if (p.second.first!=q.second.first) return p.second.first<q.second.first;
		if (p.second.second!=q.second.second) return p.second.second>q.second.second;
		return p.first.first<q.first.first;
	});
	rep(i, n) cout << a[i].first.first << '\n';

	return 0;
}
