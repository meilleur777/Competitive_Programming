#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int ans=0;
	while (n--) {
		string s;
		cin >> s;
		set<char> st;
		bool flag=true;
		for (int i=0; i<(int)s.size(); i++) {
			if (i>0 && s[i]==s[i-1]) {
				continue;
			}
			if (st.find(s[i])!=st.end()) {
				flag=false;
				break;
			}
			st.insert(s[i]);
		}
		ans+=flag;
	}
	cout << ans;

	return 0;
}
