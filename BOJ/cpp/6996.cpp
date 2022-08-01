#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		vector<int> cnt(26, 0);
		for (auto c:a) cnt[c-'a']++;
		for (auto c:b) cnt[c-'a']--;
		cout << a << " & " << b << " are ";
		if (cnt!=vector<int>(26, 0)) {
			cout << "NOT ";
		}
		cout << "anagrams.\n";
	}

	return 0;
}
