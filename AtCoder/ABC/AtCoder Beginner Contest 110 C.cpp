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
	vector<int> cnts(26, 0), cntt(26, 0);
	rep(i, s.size()) {
		cnts[s[i]-'a']++;
		cntt[t[i]-'a']++;
	}
	sort(cnts.begin(), cnts.end());
	sort(cntt.begin(), cntt.end());
	if (cnts!=cntt) {
		cout << "No";
	}
	else cout << "Yes";

	return 0;
}
