#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		string s;
		int a, b, c;
		cin >> s >> a >> b >> c;
		cout << s << ' ' << a+b+c << ' ';
		if (a+b+c>=55 && a>=11 && b>=8 && c>=12) cout << "PASS";
		else cout << "FAIL";
		cout << '\n';
		cin.ignore();
	}

	return 0;
}
