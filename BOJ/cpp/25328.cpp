#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	int d;
	vector<string> a(3);
	rep(i, 3) cin >> a[i];
	cin >> d;

	map<string, int> mp;
	set<string> tst;
	function<void(int, string, int, int)> makestring=[&](int num, string s, int now, int cnt) {
		if (cnt==d) {
			tst.insert(s);
			return;
		}
		if (now==(int)a[num].size()) return;
		for (int i=now; i<(int)a[num].size(); i++) {
			makestring(num, s+a[num][i], i+1, cnt+1);
		}
	};
	rep(i, 3) {
		set<string> t;
		tst=t;
		makestring(i, "", 0, 0);
		for (auto j:tst) mp[j]++;
	}

	set<string> st;
	for (auto p:mp) {
		if (p.second>1) {
			st.insert(p.first);
		}
	}
	if (st.empty()) cout << -1;
	else for (auto i:st) cout << i << '\n';

	return 0;
}
