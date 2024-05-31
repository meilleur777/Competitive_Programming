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

	string S, T;
	cin >> S >> T;
	
	int ans = 0;	
	for (int i = 0; i < 3; i++) {
		if (S[i] == T[i]) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}
