#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

bool solve(string& k) {
	for (int i = 1; i < k.size(); i++) {
		if (k[i]-k[i-1] != k[1]-k[0]) {
			return false;
		}
	}
	return true;
}

int main() {
	init_code();

	string k;
	cin >> k;
	if (solve(k)) {
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	}
	else {
		cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
	}

	return 0;
}
