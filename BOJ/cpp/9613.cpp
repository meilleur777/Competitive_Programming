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

int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

int main() {
	init_code();

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> A(n);
		rep(i, n) {
			cin >> A[i];
		}
		ll sum = 0;
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(A[i], A[j]);
			}
		}
		cout << sum << '\n';
	}

	return 0;
}
