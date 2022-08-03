#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ptr=0;
		while (ptr<(int)s.size() && s[ptr]=='U') {
			ptr++;
		}
		cout << ptr << '\n';
	}

	return 0;
}
