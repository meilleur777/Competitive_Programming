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

	int X;
	cin >> X;
	for (int i = 1; i*100 <= X; i++) {
		if ((X-i*100+4)/5 <= i) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
