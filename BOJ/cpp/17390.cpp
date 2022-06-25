#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	v.push_back(0);
	sort(v.begin(), v.end());
	rep(i, n) v[i+1]+=v[i];
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << v[b]-v[a-1] << '\n';
	}

	return 0;
}
