#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cout << fixed;
	cout.precision(6);
	
	int n;
	while (cin >> n) {
		vector<pair<long double, long double>> v(n);

		for (int i=0; i<n; i++) {
			cin >> v[i].first >> v[i].second;
		}

		cout << n  << ' ';
		for (int i=0; i<n; i++) {
			cout << (v[i].first+v[(i+1)%n].first)/2 << ' '
			<< (v[i].second+v[(i+1)%n].second)/2 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
