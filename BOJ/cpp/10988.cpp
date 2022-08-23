#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin >> s;
	rep(i, (int)s.size()) {
		if (s[i]!=s[(int)s.size()-i-1]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}
