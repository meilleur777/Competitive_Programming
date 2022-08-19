#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s;
	getline(cin, s);
	for (auto c:s) {
		if (!isalpha(c)) cout << c;
		else if (isupper(c)) {
			cout << char('A'+(c-'A'+13)%26);
		}
		else {
			cout << char('a'+(c-'a'+13)%26);
		}
	}

	return 0;
}
