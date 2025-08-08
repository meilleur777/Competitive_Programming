#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (true) {
		int n;
		cin >> n;
		if (n==0) break;
		cin.ignore();

		string s;
		getline(cin, s, '\n');

		for (int i=0; i<(int)s.size(); i++) {
			s.erase(remove(s.begin(), s.end(), ' '), s.end());
		}
		for (auto &c: s) {
			c=toupper(c);
		}

		int idx=0;
		int cnt=0;
		int now=0;
		string ans((int)s.size(), '-');
		while (now<(int)s.size()) {
			ans[idx]=s[now];
			idx+=n;
			if (idx>=(int)s.size()) {
				idx=cnt+1;
				cnt++;
			}
			now++;
		}

		cout << ans << '\n';
	}

	return 0;	
}