#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto i:v) {
		cout << i << ' ';
	}

	return 0;
}
