#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	map<string, int> mp;

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		s=s.substr(s.find('.')+1);
		mp[s]++;
	}

	for (auto i:mp) {
		cout << i.first << ' ' << i.second << '\n';
	}

	return 0;
}
