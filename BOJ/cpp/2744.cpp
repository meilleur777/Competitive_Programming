#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;
	for (auto c:s) {
		if (isupper(c)) cout << char(c-'A'+'a');
		else cout << char(c-'a'+'A');
	}

	return 0;
}
