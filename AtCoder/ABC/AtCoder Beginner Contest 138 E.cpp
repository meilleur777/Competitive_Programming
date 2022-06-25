#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	string s, t;
	cin >> s >> t;
	vector<int> cnt(26, 0);
	vector<vector<int>> pla(26);
	for (int i=0; i<s.size(); i++) {
		cnt[s[i]-'a']++;
		pla[s[i]-'a'].push_back(i);
	}
	ll ptr=0;
	ll ans=0;
	ll memo=INF;
	vector<int> now=cnt;
	while (true) {
		int c=t[ptr]-'a';
		if (cnt[c]==0)	{
			cout << -1;
			return 0;
		}
		if (now[c]==0) {
			ans++;
			now=cnt;
			now[c]--;
			memo=pla[c][0];
		}
		else {
			auto tmp=upper_bound(pla[c].begin(), pla[c].end(), memo);
			if (tmp==pla[c].end()) {
				ans++;
				now=cnt;
				memo=pla[c][0];
				now[c]--;
			}
			else {
				memo=*tmp;
				now[c]--;
			}
		}
		ptr++;
		if (ptr==t.size()) {
			cout << (ans-1)*s.size()+memo+1;
			return 0;
		}
	}	

	return 0;
}
