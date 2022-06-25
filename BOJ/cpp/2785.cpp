#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	sort(v.begin(), v.end());
	int now=n-1;
	for (int i=0; i<n; i++) {
		while (v[i] && i<now) {
			now--;
			v[i]--;
		}
	}
	cout << n-1-now;

	return 0;
}
