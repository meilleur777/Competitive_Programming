#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

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

int main() {
	init_code();

	string S[4];
	for (int i = 0; i < 4; i++) {
		cin >> S[i];
	}

	int chk[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		if (S[i] == "3B") {
			chk[0]++;
		}
		else if (S[i] == "2B") {
			chk[1]++;
		}
		else if (S[i] == "H") {
			chk[2]++;
		}
		else {
			chk[3]++;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (!chk[i]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}
