#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	int ans=0;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;

		if (s.find("01")!=string::npos || s.find("OI")!=string::npos) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}
