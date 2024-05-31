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

	string s;
	cin >> s;
	string t=s;
	if (s.size()==26 && !next_permutation(t.begin(), t.end())) {
		cout << -1;
		return 0;
	}
	set<char> m;
	for (auto i:s) m.insert(i);
	if (s.size()==26) {
		for (int i=25; i>=0; i--) {
			for (int j=s[i]-'a'+1; j<26; j++) {
				if (m.find(char(j+'a'))==m.end()) {
					cout << s.substr(0, i)+char(j+'a');
					return 0;
				}
			}
			m.erase(m.find(s[i]));
		}
	}
	else {
		cout << s;
		for (int i=0; i<26; i++) {
			if (m.find(char(i+'a'))==m.end()) {
				cout << char(i+'a');
				return 0;
			}
		}
	}

	return 0;
}
