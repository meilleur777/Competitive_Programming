#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
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

	string a, b;
	cin >> a >> b;
	a+=b;
	int c=stoi(a);
	for (int i=1; i*i<=c; i++) {
		if (i*i==c) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";

	return 0;
}
