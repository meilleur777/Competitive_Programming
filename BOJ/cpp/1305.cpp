#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int l;
	string s;
	cin >> l >> s;
	vector<int> fail(l, 0);
	for (int i=1, j=0; i<l; i++) {
		while (j>0 && s[i]!=s[j]) j=fail[j-1];
		if (s[i]==s[j]) {
			j++;
			fail[i]=j;
		}
	}
	cout << l-fail.back();

	return 0;
}
