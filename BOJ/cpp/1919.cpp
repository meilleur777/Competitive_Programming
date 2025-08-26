#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string a, b;
	cin >> a >> b;

	vector<int> cnta(26, 0), cntb(26, 0);

	for (auto c:a) {
		cnta[c-'a']++;
	}
	for (auto c:b) {
		cntb[c-'a']++;
	}

	int ans=0;
	for (int i=0; i<26; i++) {
		ans+=abs(cnta[i]-cntb[i]);
	}

	cout << ans;

	return 0;
}
