#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	cout << fixed;
	cout.precision(2);

	int t;
	cin >> t;
	while (t--) {
		ld a;
		cin >> a;
		string s;
		getline(cin, s);
		for (auto c:s) {
			switch (c) {
				case '@': a*=3; break;
				case '%': a+=5; break;
				case '#': a-=7; break;
			}
		}
		cout << a << '\n';
	}

	return 0;
}
