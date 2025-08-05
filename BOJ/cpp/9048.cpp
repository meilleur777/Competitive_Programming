#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	for (int tc=0; tc<t; tc++) {
		int f, r, n;
		cin >> f >> r >> n;

		int ans=r+2*f+1;
		vector<vector<int>> v(f+1);
		for (int i=0; i<n; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}

		for (int i=0; i<=f; i++) {
			sort(v[i].begin(), v[i].end());
		}

		for (int i=1; i<=f; i++) {
			if (v[i].empty()) continue;

			int tmp=0x3f3f3f3f;

			tmp=min(tmp, v[i].back()*2);
			tmp=min(tmp, (r+1-v[i].front())*2);
			for (int j=0; j<(int)v[i].size()-1; j++) {
				tmp=min(tmp, v[i][j]*2+(r+1-v[i][j+1])*2);
			}
			ans+=tmp;
		}

		cout << ans << '\n';
	}

	return 0;
}
