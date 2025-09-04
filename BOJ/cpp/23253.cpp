#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(m);

	for (int i=0; i<m; i++) {
		int k;
		cin >> k;
		for (int j=0; j<k; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
		}
	}

	bool flag=true;
	for (int i=0; i<m; i++) {
		for (int j=0; j<(int)v[i].size()-1; j++) {
			if (v[i][j]<v[i][j+1]) {
				flag=false;
			}
		}
	}

	if (flag) cout << "Yes";
	else cout << "No";

	return 0;
}
