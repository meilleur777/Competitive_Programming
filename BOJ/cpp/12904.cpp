#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	while ((int)t.size()>1) {
		if (t.back()=='A') {
			t=t.substr(0, (int)t.size()-1);
		}
		else {
			t=t.substr(0, (int)t.size()-1);
			reverse(t.begin(), t.end());
		}
		if (s==t) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
