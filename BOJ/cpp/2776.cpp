#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		set<int> st;
		cin >> n;
		while (n--) {
			int a;
			cin >> a;
			st.insert(a);
		}
		cin >> m;
		while (m--) {
			int a;
			cin >> a;
			cout << (st.find(a)!=st.end()) << '\n';
		}
	}

	return 0;
}
