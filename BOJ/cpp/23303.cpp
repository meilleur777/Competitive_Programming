#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	getline(cin, s);
	for (int i=0; i<(int)s.size()-1; i++) {
		string t=s.substr(i, 2);
		if (t=="D2" || t=="d2") {
			cout << "D2";
			return 0;
		}
	}
	cout << "unrated";	

	return 0;
}
