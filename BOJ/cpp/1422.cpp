#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int k, n;
	cin >> k >> n;
	vector<int> a(k);
	rep(i, k) cin >> a[i];
	sort(a.begin(), a.end());
	vector<string> s;
	rep(i, k) s.push_back(to_string(a[i]));
	rep(i, n-k) s.push_back(to_string(a.back()));
	sort(s.begin(), s.end(), [&](string p, string q) {
		return p+q>q+p;
	});
	for (auto i:s) cout << i;

	return 0;
}
