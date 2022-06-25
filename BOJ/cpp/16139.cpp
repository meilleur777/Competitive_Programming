#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	s="1"+s;
	vector<vector<int>> cnt(26, vector<int>((int)s.size(), 0));
	for (int i=1; i<(int)s.size(); i++) {
		cnt[s[i]-'a'][i]++;
		rep(j, 26) {
			cnt[j][i]+=cnt[j][i-1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		r++;
		cout << cnt[c-'a'][r]-cnt[c-'a'][l] << '\n';
	}

	return 0;
}
