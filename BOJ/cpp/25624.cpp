#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long n, m;
	cin >> n >> m;
	vector<string> v(m);
	for (int i=0; i<m; i++) {
		cin >> v[i];
	}

	vector<bool> used(26, false);
	vector<set<char>> ans(n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (used[v[j][i]-'A']==true) {
				cout << "NO";
				exit(0);
			}
			ans[i].insert(v[j][i]);
		}

		for (int j=0; j<m; j++) {
			used[v[j][i]-'A']=true;
		}
	}

	long long tmp=1;
	for (int i=0; i<n; i++) {
		if (ans[i].empty()) continue;

		tmp*=(int)ans[i].size();
	}
	if (m!=tmp) {
		cout << "NO";
		exit(0);	
	}

	set<string> chk;
	for (int i=0; i<m; i++) {
		chk.insert(v[i]);
	}
	if (chk.size()!=m) {
		cout << "NO";
		exit(0);
	}

	cout << "YES\n";
	for (int i=0; i<n; i++) {
		for (auto c:ans[i]) {
			cout << c;
		}
		cout << '\n';
	}

	return 0;
}
