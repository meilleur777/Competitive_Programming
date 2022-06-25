#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	vector<int> cnt(26, 0);
	while (cin >> s) for (auto i:s) cnt[i-'a']++;
	int mx=*max_element(cnt.begin(), cnt.end());
	rep(i, 26) if (mx==cnt[i]) cout << char(i+'a');

	return 0;
}
