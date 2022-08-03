#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		string t;
		int ptr=0;
		while (ptr<(int)s.size()) {
			if (s[ptr]==' ') {
				reverse(t.begin(), t.end());
				cout << t << ' ';
				t="";
			}
			else {
				t+=s[ptr];
			}
			ptr++;
		}
		reverse(t.begin(), t.end());
		cout << t << '\n';
		// cin.ignore();
	}

	return 0;
}
