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

	int A, B, C;
	cin >> A >> B >> C;
	while (C--) {
		B++;
		if (B == 60) {
			B = 0;
			A++;
			if (A == 24) {
				A = 0;
			}
		}
	}	
	cout << A << ' ' << B;

	return 0;
}
