#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string st="AEIOUaeiou";

	int s;
	cin >> s;
	cin.ignore();
	while (s--) {
		string q;
		getline(cin, q);
		int t=0;
		int p=0;
		for (auto c:q) {
			if (c==' ') continue;
			if (find(st.begin(), st.end(), c)!=st.end()) {
				t++;
			}
			else p++;
		}
		cout << p << ' ' << t << '\n';
	}

	return 0;
}
