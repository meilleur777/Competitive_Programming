#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	cin.get();
	while (t--) {
		string s;
		getline(cin, s);
		if (s.empty()) cout << 1 << '\n';
		else {
			int mx=0;
			stack<char> sk;
			for (auto i:s) {
				if (i=='[') {
					sk.push(i);
					mx=max(mx, (int)sk.size());
				}
				else sk.pop();
			}
			cout << (ll)pow(2, mx) << '\n';
		}
	}

	return 0;
}
