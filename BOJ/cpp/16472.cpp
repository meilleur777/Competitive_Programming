#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int ans=0;
	vector<int> cnt(26, 0);
	set<char> st;
	int left=0;
	for (int right=0; right<(int)s.size(); right++) {
		cnt[s[right]-'a']++;
		if (cnt[s[right]-'a']==1) st.insert(s[right]);
		while (st.size()>n) {
			cnt[s[left]-'a']--;
			if (cnt[s[left]-'a']==0) st.erase(s[left]);
			left++;
		}
		ans=max(ans, right-left+1);
	}
	cout << ans;

	return 0;
}
