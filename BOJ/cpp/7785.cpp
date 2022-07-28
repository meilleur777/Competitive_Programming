#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	set<string> st;
	while (n--) {
		string s, ss;
		cin >> s >> ss;
		if (ss=="enter") {
			st.insert(s);
		}
		else {
			st.erase(s);
		}
	}
	vector<string> ans;
	for (auto c:st) ans.push_back(c);
	for (int i=(int)ans.size()-1; i>=0; i--) {
		cout << ans[i] << '\n';
	}

	return 0;
}
