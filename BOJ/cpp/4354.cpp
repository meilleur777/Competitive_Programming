#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	while (true) {
		string s;
		cin >> s;
		if (s==".") break;
		int n=(int)s.size();
		vector<int> fail(n, 0);
		for (int i=1, j=0; i<n; i++) {
			while (j>0 && s[i]!=s[j]) j=fail[j-1];
			if (s[i]==s[j]) {
				j++;
				fail[i]=j;
			}
		}
		int tmp=n-fail.back();
		if (n%tmp) cout << 1 << '\n';
		else cout << n/tmp << '\n';
	}

	return 0;
}
