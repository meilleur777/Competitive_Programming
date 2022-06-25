#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		vector<int> r(N), p(N);	
		rep(i, N) cin >> r[i];
		rep(i, N) cin >> p[i];
		int b = r[0];
		for (int i = 1; i < N; i++) {
			b = gcd(b, r[i]);
		}	
		int a = b;
		for (int i = 0; i < N; i++) {
			a = max(a, (p[i]*b+r[i]-1)/r[i]);
		}
		for (int i = 0; i < N; i++) {
			cout << r[i]*a/b-p[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}	
