#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;

	set<int> st;
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i]=='B') st.insert(i);
	}

	int ans=0;
	for (int i=(int)s.size()-1; i>=0; i--) {
		if (s[i]!='A') continue;
		if (!st.empty() && *st.rbegin()>i) {
			ans++;
			st.erase(*st.rbegin());
		}
	}
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i]!='C') continue;
		if (!st.empty() && *st.begin()<i) {
			ans++;
			st.erase(*st.begin());
		}
	}
	cout << ans;

	return 0;
}
