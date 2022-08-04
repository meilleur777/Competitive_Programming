#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;
	vector<int> cnt(26, 0);
	for (auto c:s) cnt[c-'a']++;
	for (auto i:cnt) cout << i << ' ';

	return 0;
}
