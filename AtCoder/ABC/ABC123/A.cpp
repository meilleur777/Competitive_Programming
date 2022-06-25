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

	vector<int> A(5);
	int k;
	rep(i, 5) cin >> A[i];
	cin >> k;
	for (int i = 0; i < 5; i++) {
		for (int j = i+1; j < 5; j++) {
			if (A[j]-A[i] > k) {
				cout << ":(";
				return 0;
			}
		}
	}
	cout << "Yay!";

	return 0;
}
