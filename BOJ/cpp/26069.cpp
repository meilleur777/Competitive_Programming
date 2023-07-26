#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	set<string> st;
	string chongstring="ChongChong";
	for (int i=0; i<n; i++) {
		string a, b;
		cin >> a >> b;
		if (a==chongstring || b==chongstring) {
			st.insert(a);
			st.insert(b);
		}
		else if (st.find(a)==st.end() && st.find(b)==st.end()) continue;
		else {
			st.insert(a);
			st.insert(b);
		}
	}
	cout << (int)st.size();

	return 0;
}
