#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<int> v;

	for (int i=0; i<n; i++) {
		int k;
		cin >> k;

		vector<int> tmpV(k);
		for (int i=0; i<k; i++) {
			cin >> tmpV[i];
		}

		v.push_back(tmpV.front());
		v.push_back(tmpV.back());
	}

	sort(v.begin(), v.end());

	cout << v[(int)v.size()/2-1];

	return 0;
}
