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

	char b;
	cin >> b;
	if (b == 'A') {
		cout << 'T';
	}
	else if (b == 'T') {
		cout << 'A';
	}
	else if (b == 'C') {
		cout << 'G';
	}
	else {
		cout << 'C';
	}

	return 0;
}
