#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while (true) {
		string s;
		getline(cin, s);
		if (s=="END") break;

		reverse(s.begin(), s.end());
		cout << s << '\n';
	}

	return 0;
}
