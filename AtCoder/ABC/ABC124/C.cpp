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

int main() {
	init_code();

	string S;
	cin >> S;
	int can1 = 0, can2 = 0;
	for (int i = 0; i < S.size(); i++) {
		if (i%2) {
			if (S[i] == '0') {
				can2++;
			}
			else {
				can1++;
			}
		}
		else {
			if (S[i] == '0') {
				can1++;
			}
			else {
				can2++;
			}
		}
	}
	cout << min(can1, can2);

	return 0;
}
