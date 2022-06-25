#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	while (true) {
		int m;
		cin >> m;
		if (m==0) break;
		string s;
		cin.ignore();
		getline(cin, s);
		map<char, int> mp;
		int nxt=0;
		int ans=0;
		for (int i=0; i<(int)s.size(); i++) {
			while (nxt<(int)s.size() && ((int)mp.size()<m || mp.find(s[nxt])!=mp.end())) {
				mp[s[nxt]]++;
				nxt++;
			}
			ans=max(ans, nxt-i);
			mp[s[i]]--;
			if (mp[s[i]]==0) mp.erase(s[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}
