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

	int A, B, K;
	cin >> A >> B >> K;
	int cnt = 0;
	vector<int> can;
	for (int i = 1; i <= min(A, B); i++) {
		if (A%i == 0 && B%i == 0) {
			can.push_back(i);
		}
	}
	cout << can[can.size()-K];

	return 0;
}
