#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	vector<pair<int, char>> cnt(26);
	rep(i, 26) cnt[i]={0, i+'A'};
	for (auto c:s) cnt[c-('a'-'A')*(c>='a')-'A'].first++;
	sort(cnt.begin(), cnt.end());
	if (cnt[25].first==cnt[24].first) cout << '?';
	else cout << cnt[25].second;

	return 0;
}
