#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	getline(cin, s);
	string t("UCPC");
	int ptr=0;
	for (auto i:s) {
		if (ptr<4 && i==t[ptr]) {
			ptr++;
		}
	}
	if (ptr==4) cout << "I love UCPC";
	else cout << "I hate UCPC";

	return 0;
}
