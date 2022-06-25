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

ll solve(ll A) {
	switch (A%4) {
		case 0: return A; break;
		case 1: return 1; break;
		case 2: return A+1; break;
		case 3: return 0;
	}
}

int main() {
	init_code();

	ll A, B;
	cin >> A >> B;
	B=solve(B);
	if (A) B^=solve(A-1);
	cout << B;

	return 0;
}
