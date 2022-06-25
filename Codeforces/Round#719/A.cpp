#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		char memo = s[0];
		vector<bool> chk(30, false);
		chk[s[0]-'A'] = true;
		bool flag = true;
		for (int i = 1; i < s.size(); i++) {
			if (memo != s[i]) {
				if (chk[s[i]-'A']) {
					cout << "No\n";
					flag = false;
					break;
				}
				else {
					chk[s[i]-'A'] = true;
					memo = s[i];
				}
			}
		}
		if (flag) cout << "Yes\n";
	}

	return 0;
}
