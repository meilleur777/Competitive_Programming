#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n==0 && m==0) break;

		set<string> st;
		vector<string> cand;
		map<string, vector<string>> mp;

		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			st.insert(s);
			cand.push_back(s);
		}

		for (int i=0; i<m; i++) {
			string a, b;
			cin >> a >> b;

			if (st.find(b)==st.end()) {
				cand.push_back(b);
				st.insert(b);
			}

			mp[b].push_back(a);
		}

		for (auto s:cand) {
			for (auto name:mp[s]) {
				cout << name << '\n';
			}
		}
	}

	return 0;
}
