#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int h, w;
		cin >> h >> w;
		vector<string> a(h);
		rep(i, h) cin >> a[i];
		rep(i, h) {
			reverse(a[i].begin(), a[i].end());
			cout << a[i] << '\n';
		}
	}

	return 0;
}
