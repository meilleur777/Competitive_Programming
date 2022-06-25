#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	getline(cin, s);
	int ans=0;
	for (auto i:s) ans+=(int)i;
	cout << char(ans/(int)s.size());

	return 0;
}
