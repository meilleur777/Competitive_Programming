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

	int N;
	cin >> N;
	string M;
	cin >> M;
	int K;
	cin >> K;
	reverse(M.begin(), M.end());
	for (int i = 0; i < M.size(); i++) {
		if (M[i] == '1') {
			if (K > i) {
				cout << "NO";
			}
			else {
				cout << "YES";
			}
			return 0;
		}
	}
	cout << "YES";

	return 0;
}
